#!/usr/bin/env python
# =====================================================================
import unittest
import sys
import json

from os import path
sys.path.append(path.dirname(path.abspath("..")))

from v4l2.pyv4l2 import Device

CURDIR = path.dirname(path.abspath(__file__))


class TestDeviceStandard(unittest.TestCase):
    VIDEODEVS_PATH = path.join(CURDIR, 'videodevs.json')

    def setUp(self):
        self.config = json.load(open(self.VIDEODEVS_PATH, "r"))
        self.devconfig = self.config['devices'][1]
        self.device = Device(str(self.devconfig['dev']))

    def tearDown(self):
        self.device.Close()

    def test_set_get_standard(self):
        # Test set NTSC_M
        self.device.SetStandard(0x1000)
        std=self.device.GetStandard()
        self.assertEquals(std, 0x1000)


if __name__ == '__main__':
    unittest.main()
