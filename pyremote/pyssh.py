from pexpect import pxssh

s = pxssh.pxssh()
s.force_password = True
pwd = 'raspberry'
lgi = 'pi'
hst = '192.168.0.11'

s.login(hst, lgi,pwd)
