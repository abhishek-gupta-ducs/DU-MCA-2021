#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <error.h>
#include <string.h>
#define BUFFERSIZE 1024
void create (char* file , char* mode)
{
    //function to create file
    //first checking if the mode is correct or not 
    if ((atoi(mode)<0) || (atoi(mode)>777))
    {
        printf("Incorrect mode : %s\n" , mode);
        return;
    }
    //converting mode decimal to octal
    int octal_mode = strtol(mode,NULL,8);
    /**now checking if the file user wants to create is already existing or not
    for that I am using access system call.
    access(fileName, F_ok) will return 0 if file already exist.**/
    if (access(file,F_OK) == 0)
    {
        int flag = 1;
        printf("WARNING !! File %s already exist.\n",file);
        printf("Enter 1 to truncate it or else 0 to exit.\n");
        scanf("%d",&flag);
        if (flag != 1)
        {
            printf("---------------------GoodBye---------------------\n");
            return;
        }
    }
    //creating file
    int fd = creat(file,octal_mode);
    if (fd == -1)
    {
        perror("ERROR");
    }
    else 
    {
        printf("File created succesfully with file descriptor = %d\n",fd);
    }
    close(fd);
}

void reading (char* file , int bytes_left , int where_to , int write_file_Desc)
{   
    //reading function to read no of bytes of a file from specific position
    char buff[BUFFERSIZE];
    int fd;
    //opening file in reading mode
    if ((fd = open(file,O_RDONLY)) == -1)
    {
        perror("Error in opening file");
        return;
    }
    if (where_to != 0)
    {
        //if user wants to read from a specific position
        if (lseek(fd,where_to,0)==-1) 
        {
                perror("Error in jumping to specific position ");
                return;
        }    
    }
    int count,totalBytesRead = 0;
    //start reading file
    while ((bytes_left > 0) && (count = read(fd,buff,BUFFERSIZE))>0)
    {
        /**logic is either byte_read (bytes left to read) get 0 or 
        bytes readed get 0, whichever get 0 first will break the loop **/
        if (count > bytes_left)
            count = bytes_left;
        write(write_file_Desc,buff,count); //print the data on terminal
        bytes_left -= count;
        totalBytesRead +=count;
    }
    if (count == -1)
        perror("Error while reading");
    else
        printf("\nTotal Bytes = %d\n",totalBytesRead); 
    close(fd);
}
void writing(char* file, long ByteToWrite , int where_to){
    /*Writing function to write into a file, some no of bytes from a specific position*/
    int fd, ByteWrite = 0;
    char buff[BUFFERSIZE];
    if ((fd = open(file,O_CREAT | O_WRONLY , 0666))== -1)
        perror("Error while opening file");
        return;
    if (where_to >= 0)
        lseek(fd,where_to,0); //if user wants to write from begining to anywhere
    else
        lseek(fd,0,2); //if user wants to write from the end
    printf("Enter data to write to file. Press Ctrl-D to finish.\n");
    /*Logic is that user is writing data in buffer buff
      but program will only write those no of bytes to file, which 
      is maintained by ByteToWrite or less than that.*/
    while (ByteToWrite > 0 && (fgets(buff, BUFFERSIZE, stdin) != NULL)) {
        int count = strlen(buff);
        if (ByteToWrite < count)
            //if bytes left to write are less then bytes written by the user at terminal
            count = ByteToWrite;
        if ((write(fd, buff, count)) == -1) 
        {
            perror("Error while writing");
            return;
        }
        ByteToWrite -= count; 
        ByteWrite += count; //maintaing the count of bytes written by the user
    }
    printf("\n\nBytes written to file : %d\n",ByteWrite);
    close(fd);
}

void fileStatus (char* file)
{
    /*fileStatus function will take path of file as parameter and print the following
    details of file
    1. Size of file
    2. Owner Id
    3. Group Id
    4. Inode No
    5. Permissions of file
    6. No of Disk Blocks Allocated*/
    struct stat fileStatus;
    if (stat(file , &fileStatus) == -1)
    {
        perror("File Status Error ");
        return;
    }
    printf("File size: %ld bytes\n", fileStatus.st_size);
    printf("Owner UID: %d\n", fileStatus.st_uid);
    printf("Group GID: %d\n", fileStatus.st_gid);
    printf("Inode number: %ld\n", fileStatus.st_ino);
    printf("File permissions: %o\n", fileStatus.st_mode);
    printf("Disk Block allocated: %ld\n",fileStatus.st_blocks);
}
void help ()
{
	printf("To Create a file : \n");
        printf("   ./fe -c filename mode(in octal no)\n\n");
        printf("To Read from a file : \n");
        printf("   ./fe -r filename BytesToRead OffSet\n");
        printf("   ./fe -r filename BytesToRead\n");
        printf("   ./fe -r filename\n\n");
        printf("To Write into a file : \n");
        printf("  ./fe -w filename BytesToWrite OffSet\n");
        printf("          Enter negative no as offset to \n          append data at end of file\n");
        printf("  ./fe -w filename BytesToWrite\n");
        printf("  ./fe -w filename\n\n");
        printf("To Copy a file : \n");
        printf("  ./fe -cp sourceFile DestinationFile\n\n");
        printf("To get stats of a file : \n");
        printf("  ./fe -stat filename\n\n");
}
int main (int argc , char** argv)
{   
    /*
    	fe = file editor program is command line base program , which provide following functionalities
    	1. Creating a file in any mode provided by the user (mode in octal number only)
    	2. Reading from a file 
    		a. User can read whole file.
    		b. User can read only some bytes of file.
    		c. User can read only some bytes of file, from any offset of file.
    	3. Wrinting into a file
    		a. User can write any number of bytes in a file
    		b. User can write some number of bytes in a file
    		c. User can override the data of file (if user sends a positive number including 0 as offset )
    		d. User can append into the file (if user sends any negative number as offset)
    	4. Creating copy of a file , User needs to provide source and destination of file
    	5. Stats of a file , User will get following information of the file
    		a. Size of file
    		b. Owner Id
    		c. Group Id
    		d. Inode No
    		e. Permissions of file
    		f. No of Disk Blocks Allocated
    	If user wants to know the format of commands he can just execute the object file without any arguments.
    */

    //If user wants to see the commands of the program
    if (argc == 1)
    {
        help();
        return 0;
    }
    //If user wants to create the file
    if ((argc == 4) && !(strcmp(argv[1],"-c")))
    {
        create(argv[2],argv[3]); //create(fileName,Mode)
    }

    //If user wants to read the file
    else if (!(strcmp(argv[1],"-r")) && (argc >= 3 && argc <=5))
    {
        if (argc == 5)
            reading(argv[2],atoi(argv[3]),atoi(argv[4]),1); //reading(fileName, BytesToRead , StartOffset ,Terminal fileDescriptor)
        else if (argc == 4)
            reading(argv[2],atoi(argv[3]),0,1); //reading(fileName, BytesToRead , StartOffset ,Terminal fileDescriptor)
        else 
            reading(argv[2],__INT_MAX__,0,1); //reading(fileName, BytesToRead , StartOffset ,Terminal fileDescriptor)
    }
    //If user wants to write into a file
    else if (!(strcmp(argv[1],"-w")) && (argc >= 3 && argc <=5))
    {
        //writing(fileName, ByteToWrite , start offset)
        if (argc == 5)
            writing(argv[2],strtol(argv[3],NULL,10),atoi(argv[4])); 
        else if (argc == 4)
            writing(argv[2],strtol(argv[3],NULL,10),-1); //by default it will write in the end
        else
            writing(argv[2],__LONG_LONG_MAX__,-1);
    }
    //If user wants to copy a source file into destination file
    else if (!strcmp(argv[1],"-cp") && argc == 4)
    {
        int dest_FD; //creating file descriptor for destination file
        if ((dest_FD = open(argv[3],O_CREAT | O_WRONLY , 0666)) == -1)
            perror("Error while opening destinaiton file ");
        else 
        {   /**reading funciton will work as copy function
            if we send destination file descriptor instead of 1 as 
            writing descriptor argument **/
            //reading(Source fileName, BytesToRead , StartOffset , Destination fileDescriptor)
            reading(argv[2],__INT_MAX__,0,dest_FD); 
        }
    }
    //If user wants to get stat of a file
    else if (!strcmp(argv[1],"-stat") && argc == 3)
    {
        fileStatus(argv[2]); //fileStatus(fileName)
    }
    //If user insert any wrong command
    else
    {
        printf("Invalid Command\n");
        help();
    }
}
