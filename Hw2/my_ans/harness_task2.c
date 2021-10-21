//The following codes are modified in ntpq.c

//Replace ntpqmain(int argc, char *argv[])
int ntpqmain(
	int argc,
	char *argv[])
{
#ifdef __AFL_HAVE_MANUAL_CONTROL
	__AFL_INIT();
#endif
	int datatype = 0;
	int status = 0;
	char data[1024 * 16] = {0};
	int length = 0;
#ifdef __AFL_HAVE_MANUAL_CONTROL
	while (__AFL_LOOP(1000))
	{
#endif
		datatype = 0;
		status = 0;
		memset(data, 0, 1024 * 16);
		read(0, &datatype, 1);
		read(0, &status, 1);
		length = read(0, data, 1024 * 16);
		cookedprint(datatype, length, data, status, stdout);
#ifdef __AFL_HAVE_MANUAL_CONTROL
	}
#endif
	return 0;
}


/*
Add the following code in nextvar(int *datalen,char **datap,char **vname,char **vvalue)

Like:

int nextvar(
	int *datalen,
	char **datap,
	char **vname,
	char **vvalue)
{
	memset(vname, 0, sizeof(vname));   //here
	memset(vvalue, 0, sizeof(vvalue)); //here
	
	...
*/
memset(vname, 0, sizeof(vname));
memset(vvalue, 0, sizeof(vvalue));
