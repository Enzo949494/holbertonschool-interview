#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.
Prints statistics every 10 lines and/or on keyboard interruption (CTRL+C).
"""

import sys


if __name__ == "__main__":
    # Initialize status code counters for valid HTTP status codes
    status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    line_count = 1
    total_file_size = 0

    def parse_log_line(line):
        """Parse log line and extract status code and file size"""
        try:
            # Split line into tokens and get last two elements
            tokens = line.split()
            status_code = tokens[-2]
            file_size = tokens[-1]

            # Update status code counter if valid
            if status_code in status_codes:
                status_codes[status_code] += 1

            # Return file size as integer
            return int(file_size)
        except (IndexError, ValueError):
            # Return 0 if parsing fails (invalid format)
            return 0

    def print_statistics():
        """Print current statistics in required format"""
        print("File size: {}".format(total_file_size))
        # Print status codes in ascending order, only if count > 0
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print("{}: {}".format(code, status_codes[code]))

    try:
        # Process each line from stdin
        for line in sys.stdin:
            total_file_size += parse_log_line(line)

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_statistics()

            line_count += 1
    except KeyboardInterrupt:
        # Print stats on CTRL+C and preserve traceback
        print_statistics()
        raise

    # Print final statistics
    print_statistics()
