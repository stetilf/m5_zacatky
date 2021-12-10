#/bin/bash
URL=https://thingspeak.com/channels/1604144


read_key=D2MCKNKFMGLTSUZ2
api_key=67NLXIL9JFQK757S
f1val=11


set `uptime -p`
  minutes=0

  shift
  while [ -n "$1" ]; do
    case $2 in
      day*)
        ((minutes+=$1*1440))
        ;;
      hour*)
        ((minutes+=$1*60))
        ;;
      minute*)
        ((minutes+=$1))
        ;;
    esac
   shift
   shift
  done
  echo $minutes

curl --data "api_key=$api_key&field1=$minutes" https://api.thingspeak.com/update
