#v4l2 unittests

This project is based on # python-video4linux2 from http://code.google.com/p/python-video4linux2.
Target is to modify it and create a basic set of python unittests for individual camera sensor or module.
Utilize as much as possible of the python's awesome unittesting framework.

## Building (C library)
make

## Testing setup
The testing setup is optimised against ViVi (http://linuxtv.org/wiki/index.php/VIVI).
To enable vivi on linux kernel environment run
sudo modprove vivi

## Testing with coverage
nosetests --with-coverage --cover-html --cover-package=v4l2
