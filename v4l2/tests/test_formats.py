#!/usr/bin/env python
# =====================================================================
import unittest
import sys
import json

from os import path
sys.path.append(path.dirname(path.abspath("..")))

from v4l2.pyv4l2 import Device

CURDIR = path.dirname(path.abspath(__file__))


class TestDeviceFormats(unittest.TestCase):
    VIDEODEVS_PATH = path.join(CURDIR, 'videodevs.json')

    def setUp(self):
        self.config = json.load(open(self.VIDEODEVS_PATH, "r"))
        self.devconfig = self.config['devices'][1]
        self.device = Device(str(self.devconfig['dev']))

    def tearDown(self):
        self.device.Close()

    def test_enumerate_formats(self):
        self.device.QueryCaps()
        self.assertEquals(self.device.driver, self.devconfig['driver'])
        self.assertEquals(self.device.card, self.devconfig['card'])
        self.assertEquals(self.device.businfo, self.devconfig['businfo'])
        self.assertEquals(self.device.caps, self.devconfig['caps'])

    def test_enumerate_formats(self):
        self.device.QueryCaps()
        self.assertEquals(self.device.driver, self.devconfig['driver'])
        self.assertEquals(self.device.card, self.devconfig['card'])
        self.assertEquals(self.device.businfo, self.devconfig['businfo'])
        self.assertEquals(self.device.caps, self.devconfig['caps'])

if __name__ == '__main__':
    unittest.main()
