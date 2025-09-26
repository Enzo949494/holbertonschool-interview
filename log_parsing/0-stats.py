#!/usr/bin/python3
import sys
import re
import signal

total_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

def print_stats():
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        if status_counts[status] > 0:
            print("{}: {}".format(status, status_counts[status]))

def signal_handler(signum, frame):
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
        print_stats()  # Always print stats at the end
    except KeyboardInterrupt:
        print_stats()
        raise
