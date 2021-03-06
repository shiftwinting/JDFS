/**
    JDFSServer: http server component of JDFS
    Copyright (C) 2017  zhang jun
    contact me: zhangjunhust@hust.edu.cn
    		http://www.cnblogs.com/junhuster/
    		http://weibo.com/junhuster

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 **/
#include "../header/JDFSServer.h"
#include "../header/network.h"
int node_num_self;
int main(int argc, char *argv[])
{
	if(argc!=2){
		node_num_self=-1;
		printf("data node serial unknow\n");
	}else{
		char *num_str=argv[1];
		node_num_self=0;
		for(int i=0;num_str[i]!='\0';i++){
			node_num_self=node_num_self*10+(num_str[i]-'0');
		}
		printf("data node serial number is %d\n", node_num_self);
	}
	char *ip_str="192.168.137.145";
	int port=8888;
	int server_listen_fd=0;
	threadpool *pool=(threadpool *)malloc(sizeof(threadpool));
	threadpool_create(pool, 6, 20);
	Http_server_body(ip_str,port,&server_listen_fd,pool);
	destory_threadpool(pool);
	return 0;
}
