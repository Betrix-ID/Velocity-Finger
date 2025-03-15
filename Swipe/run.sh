#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ Velocity Finger' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Velocity Finger.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    : 1.0 [ SETTINGS SS ]"
    echo "       - Release               :  16 - Mar - 2025"
    echo "       - Name Shell         :  Velocity Finger"
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Velocity Finger. "
    sleep 2
    echo
     rm -rf /data/local/tmp/*
     cp /sdcard/Swipe/input /data/local/tmp 
     chmod +x /data/local/tmp/input 
       if [ "$1" = "-E" ]; then
        shell "Wait To Set Velocity Finger to Brutal Min 1-3"
        /data/local/tmp/input -E
    elif [ "$1" = "-l" ]; then
         shell "Wait To Set Velocity Finger to Medium Min 1-3"
        /data/local/tmp/input -l
    elif [ "$1" = "-d" ]; then
         shell "Wait To delete refres rate to settings Min 1-3"
         /data/local/tmp/input -d
    elif [ "$1" = "-h" ]; then
       /data/local/tmp/input -h
    else
        printf "Usage VelocityHz [-E|-l|-h]\n"
    fi
    