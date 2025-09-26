#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.

Reads lines that match the format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

After every 10 lines or on keyboard interruption (CTRL+C),
prints the total file size and the number of lines grouped by status code.
"""

import sys
import re
import signal

total_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

def print_stats():
    """
    Print the accumulated statistics.

    Outputs the total file size and counts of each HTTP status code encountered
    since the script started or since the last output.

    Only prints status codes with counts greater than zero.
    """
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        if status_counts[status] > 0:
            print("{}: {}".format(status, status_counts[status]))

def signal_handler(signum, frame):
    """
    Signal handler for graceful interruption.

    Prints current statistics before exiting when receiving SIGINT (CTRL+C).
    
    Args:
        signum (int): Signal number.
        frame (frame object): Current stack frame passing control to the handler.
    """
    print_stats()
    sys.exit(0)

if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)

    pattern = re.compile(
        r'^\d+\.\d+\.\d+\.\d+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)
            if match:
                status_code = int(match.group(1))
                file_size = int(match.group(2))
                total_size += file_size
                if status_code in status_counts:
                    status_counts[status_code] += 1
                line_count += 1
                if line_count % 10 == 0:
                    print_stats()
        print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
