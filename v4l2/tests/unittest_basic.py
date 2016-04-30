#!/usr/bin/env python
# =====================================================================

import unittest
import sys
from os import path
sys.path.append(path.dirname(path.abspath("..")))

from v4l2.pyv4l2 import Device


class TestStringMethods(unittest.TestCase):

    def test_list_devices(self):
        devices = Device.List()
        print devices

if __name__ == '__main__':
    unittest.main()
