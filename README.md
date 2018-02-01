# maxmemphp
Determine the maximum available memory on the server using php
## Foreword:
_Many unfortunately today do not consider php as a language for writing console applications, almost all of the pupils code on it WEB because of what PHP imposes a number of restrictions related to WEB, I once had a task when I was writing a CLS application, and I needed to determine how much now on the server of available memory ... After spending about 48 hours on Google, I was upset and found out that PHP can not do this routinely._

_Therefore, I had to write a small code that would return free memory on the server_

## System requirements:
**Will only work in FreeBSD x64**
## Installation:

**Step 1**
To install, simply download the files to your computer/server 
>git clone https://github.com/StasToken/maxmemphp.git

**Step 2**
Go to the folder with the downloaded files
>cd ./maxmemphp

**Step 3**
Execute the following commands in the folder with the downloaded files
> phpize

>./configure

>make

>make install

**Step 4**

After these actions, a file will appear in the folder with the libraries to your php _system_available_memory.so_ 

**Step 5**

It only remains to connect it to your php.ini 

_hint:_

To quickly find your php.ini execute in the terminal
> php -i | grep php.ini

In the answer there will be something like:

>Configuration File (php.ini) Path => /etc/php/7.0/cli
>Loaded Configuration File => /etc/php/7.0/cli/php.ini

Actually _/etc/php/7.0/cli/php.ini_ and tells us where to look for the file

We add in php.ini
>extension=system_available_memory.so 

Actually on this installation is finished

## Example of use:

```
<?php
$free_memory_server=system_available_memory(); // Return unallocated memory on the server in bytes (int)
echo $free_memory_server; // Will output something like 765834568
?>
```

### What's next

I plan to add support for other platforms - maybe even get my hands on it for WIndows but when I do it (and I'll do it at all) I have no idea .... But you can always help me :)
