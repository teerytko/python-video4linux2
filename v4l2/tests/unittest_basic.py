#!/usr/bin/env python
# =====================================================================

import unittest
import sys
from os import path
sys.path.append(path.dirname(path.abspath("..")))

from v4l2.pyv4l2 import Device


class TestDeviceBasics(unittest.TestCase):
    VIDEODEV_NAME = '/dev/video0'

    def test_list_devices(self):
        devices = Device.List()
        self.assertTrue(len(devices) > 0)
        self.assertTrue(self.VIDEODEV_NAME in devices)

    def test_open_device(self):
        devices = Device.List()
        # connect to the nth device
        d = Device(devices[0])
        self.assertTrue(d)

    def test_close_device(self):
        devices = Device.List()
        d = Device(devices[0])
        self.assertTrue(d)
        d.Close()
        self.assertEquals(d.fd, 0)
        

if __name__ == '__main__':
    unittest.main()
