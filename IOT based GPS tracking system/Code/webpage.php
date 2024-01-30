
<?php

include("config.php");
session_start();
extract($_POST);

if(isset($_POST['btn']))
{
$del=mysqli_query($con,"delete from pfd4");
}
?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<title>PFD</title>
</head>

<body>

<div align="center"><h1>BLOCK BOX</h1></div>
<table align="center" border="3" width="30%">
<tr height="50" align="center"><th><h3>SL.No</h3></th><th><h3>Date & Time</h3></th><th><h3>Message</h3></th></tr>
<?php  if($con)
	 	{
			$sqlCheckUname = mysqli_query($con,"select * from pfd4 ORDER BY id DESC");
			$i=1;
			while($rr=mysqli_fetch_array($sqlCheckUname))
			{
			?>
			<tr align="center"><td><?php echo $i;?></td><td><?php echo $rr['date'];?></td><td><?php echo $rr['msg'];?></td></tr>
		<?php
 		
		$i++;}
		
		}
		
?> 
</table>
	
<form id="form1" name="form1" method="post" action="">
	   <table width="46%" border="0" align="center">
       
         <tr>
           <td>&nbsp;</td>
           <td rowspan="2"><label>
             <input name="btn" type="submit" id="btn" value="reset" />
        
           </label></td> 
         </tr>
		 
		
		 
  </table>
</form>
	
	
	
	
	
	
	



 
	</body>
	</html>
	
	
	
	
