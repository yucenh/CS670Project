# -*- coding: utf-8 -*-
import urllib,urllib2, time, webbrowser
import os
import sys
import ctypes
import zlib

def fun(prog,level):
	a = ""
	url='http://www.hacker.org/runaway/index.php?gotolevel='+str(level)+'&go=Go+To+Level&name=yucenh@gmail.com&password=123456'
#	print url
	request = urllib2.Request(url)
	request.add_header('Accept-Encoding', 'gzip')
	response = urllib2.urlopen(request)
	a = zlib.decompress(response.read(), 16 + zlib.MAX_WBITS)
	at = a[a.find("""FVterrainString="""):]
	aat = at[at.find(""">\n""") : ]
	data = at[0:len(at)-len(aat)-1]
#	print data
	FVterrainString = data[data.find("=")+1:data.find("&")]
	data = data[data.find("&")+1:]
	FVinsMax = data[data.find("=")+1:data.find("&")]
	data = data[data.find("&")+1:]
	FVinsMin = data[data.find("=")+1:data.find("&")]
	data = data[data.find("&")+1:]
	FVboardX = data[data.find("=")+1:data.find("&")]
	data = data[data.find("&")+1:]
	FVboardY = data[data.find("=")+1:data.find("&")]
	data = data[data.find("&")+1:]
	FVlevel = data[data.find("=")+1:]
	
	print "FVterrainString:", FVterrainString
	print "FVinsMax:", FVinsMax
	print "FVinsMin:", FVinsMin
	print "FVboardX:", FVboardX
	print "FVboardY:", FVboardY
	print "FVlevel:", FVlevel
	
	ll = ctypes.cdll.LoadLibrary
	lib = ll(prog)
	r = " " * 10000
	starttime = time.clock()  
	lib.runc(FVterrainString, FVinsMax, FVinsMin, FVboardX, FVboardY, r)
	endtime = time.clock()  
	r = r[:r.find(" ") - 1]
	print r
	submit = "http://www.hacker.org/runaway/index.php?path=" +r +"&name=yucenh@gmail.com&spw=ce788d1217b0e4bd97954d697b8d8ea1"
#	time.sleep(1)
#	print submit
	s = urllib2.urlopen(submit).read()
#	print "Level", level, "done"
	print "Time elapsed: ", endtime - starttime
	
if __name__ == "__main__":
	fun(sys.argv[1],sys.argv[2])

