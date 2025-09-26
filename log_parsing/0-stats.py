#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.
Prints statistics every 10 lines and/or on keyboard interruption (CTRL+C).
"""

import sys
import re
import signal

# Global variables for signal handler access
total_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


def print_stats():
    """Print current statistics in the required format"""
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        if status_counts[status] > 0:
            print("{}: {}".format(status, status_counts[status]))


def signal_handler(signum, frame):
    """Handle CTRL+C interruption gracefully"""
    print_stats()
    sys.exit(0)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    
    # Compile regex pattern for better performance  
    pattern = re.compile(
        r'^\S+\s*-\s*\[.*\]\s*"GET\s+/projects/260\s+HTTP/1\.1"\s+(\d+)\s+(\d+)\s*$'
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
        
        # Always print final stats if not already printed at line 10, 20, etc.
        if line_count == 0 or line_count % 10 != 0:
            print_stats()
    
    except KeyboardInterrupt:
        print_stats()