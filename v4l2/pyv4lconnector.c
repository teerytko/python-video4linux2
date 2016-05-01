/* Released under the GPL v3 by Jackson Yee (jackson@gotpossum.com)
 * Copyright 2008
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <time.h>
#include <linux/ioctl.h>
#include <linux/videodev2.h>

//  =====================================================================
int Errno()
{
	return errno;
}

//  =====================================================================
char* Error()
{
	return strerror(errno);
}

//  =====================================================================
char* bool2str(int b)
{
	if (b)
		return "True";
	
	return "False";
}

//  =====================================================================
int BufferDiff(char* b1, char* b2, int size, int format)
{
	int i 		= 0;
	int count = 0;
	
	for (i = 0; i < size; i++)
	{
		if (b1[i] != b2[i])
		{
			count++;
		}
	}

	return count;
}

//  =====================================================================
int Open(char* dev)
{
	int	fd	=	open(dev, O_RDWR);
	return fd;
}

//  =====================================================================
int Close(int fd)
{
	close(fd);
	return 0;
}

//  =====================================================================
int QueryCaps(int fd, struct v4l2_capability* caps)
{
	return ioctl(fd, VIDIOC_QUERYCAP, caps);
}

//  =====================================================================
int EnumInput(int fd, struct v4l2_input* input)
{
	return ioctl(fd, VIDIOC_ENUMINPUT, input);
}

//  =====================================================================
int EnumFormat(int fd, struct v4l2_fmtdesc* input)
{
	return ioctl(fd, VIDIOC_ENUM_FMT, input);
}

//  =====================================================================
int SetInput(int fd, int input)
{
	return ioctl(fd, VIDIOC_S_INPUT, &input );
}

//  =====================================================================
int GetStandard(int fd, v4l2_std_id* std)
{
	v4l2_std_id temp = 0;
	int ret = 0;
	ret = ioctl(fd, VIDIOC_G_STD, &temp);
	*std = temp;
	return ret;
}

//  =====================================================================
int SetStandard(int fd, v4l2_std_id std)
{
	return ioctl(fd, VIDIOC_S_STD, &std);
}

//  =====================================================================
int GetFormat(int fd, struct v4l2_format* f)
{
	return ioctl(fd, VIDIOC_G_FMT, f);
}

//  =====================================================================
int SetFormat(int fd, struct v4l2_format* f)
{
	return ioctl(fd, VIDIOC_S_FMT, f);
}

//  =====================================================================
int Read(int fd, char* buf, int bufsize)
{
	return read(fd, buf, bufsize);
}

//  =====================================================================
int RequestBuffers(int fd, struct v4l2_requestbuffers* f)
{
	return ioctl(fd, VIDIOC_REQBUFS, f);
}

//  =====================================================================
int QueryBuf(int fd, struct v4l2_buffer* f)
{
	return ioctl(fd, VIDIOC_QUERYBUF, f);
}

//  =====================================================================
int Queue(int fd, struct v4l2_buffer* f)
{
	return ioctl(fd, VIDIOC_QBUF, f);
}

//  =====================================================================
int Dequeue(int fd, struct v4l2_buffer* f)
{
	return ioctl(fd, VIDIOC_DQBUF, f);
}

//  =====================================================================
int StreamOn(int fd, int type)
{
	return ioctl(fd, VIDIOC_STREAMON, &type);
}

//  =====================================================================
int StreamOff(int fd, int type)
{
	return ioctl(fd, VIDIOC_STREAMOFF, &type);
}

//  =====================================================================
void* MMap(int fd, size_t size, off_t offset)
{
	return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset);
}

//  =====================================================================
int MUnmap(void* start, size_t length)
{
	return munmap(start, length);
}

int main(int argc, char* argv)
{
	return 0;
}
