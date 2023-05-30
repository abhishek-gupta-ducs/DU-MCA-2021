# AOS_project_sem_4
File editor program is command line base program , which provide following functionalities :
<h2>1. Creating a file in any mode provided by the user (mode in octal number only)   </h2>  
       <i><b>./fe -c filename mode(in octal no)</b></i>

<h2>2. Reading from a file</h2>
        <h3>a. User can read whole file.</h3>     		
        <i><b>./fe -r filename </b></i>
        <h3>b. User can read only some bytes of file.  </h3>   		
        <i><b>./fe -r filename BytesToRead </b></i>
        <h3>c. User can read only some bytes of file, from any offset of file.  </h3>
        <i><b>./fe -r filename BytesToRead OffSet </b></i>
   	
<h2>3. Wrinting into a file   </h2>  		
    <h3>a. User can write any number of bytes in a file    </h3> 		
           <i> <b>./fe -w filename</b></i>
    <h3>b. User can write some number of bytes in a file </h3>    		
           <i> <b>./fe -w filename BytesToWrite </b></i>
    <h3>c. User can override the data of file (if user sends a positive number including 0 as offset )    </h3>
            <i><b>./fe -w filename BytesToWrite OffSet 	</b>	</i>
    <h3>d. User can append into the file (if user sends any negative number as offset)     </h3>	
            <i><b>./fe -w filename BytesToWrite NegativeOffSet </b></i>
                
<h2>4. Creating copy of a file , User needs to provide source and destination of file</h2>  
           <i> <b>./fe -cp sourceFile DestinationFile</b></i>

<h2>5. Stats of a file , User will get following information of the file</h2>	
    <p>a. Size of file   <br>  		
    b. Owner Id     	<br>	
    c. Group Id     	<br>
    d. Inode No     	<br>
    e. Permissions of file  <br>   		
    f. No of Disk Blocks Allocated   </p></i>
            <i><b>./fe -stat filename  </b></i>	
   
<h2>If user wants to know the format of commands he can just execute the object file without any arguments.</h2>
            <i><b>./fe</></i>
