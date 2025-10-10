#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data: List of integers representing bytes of data

    Returns:
        True if data is valid UTF-8 encoding, False otherwise
    """
    num_bytes = 0

    for byte in data:
        # Only consider the 8 least significant bits
        byte = byte & 0xFF

        if num_bytes == 0:
            # Determine how many bytes this character should have
            if byte >> 7 == 0:
                # 1-byte character (0xxxxxxx)
                continue
            elif byte >> 5 == 0b110:
                # 2-byte character (110xxxxx)
                num_bytes = 1
            elif byte >> 4 == 0b1110:
                # 3-byte character (1110xxxx)
                num_bytes = 2
            elif byte >> 3 == 0b11110:
                # 4-byte character (11110xxx)
                num_bytes = 3
            else:
                # Invalid starting byte
                return False
        else:
            # This should be a continuation byte (10xxxxxx)
            if byte >> 6 != 0b10:
                return False
            num_bytes -= 1

    # All characters should be complete
    return num_bytes == 0
