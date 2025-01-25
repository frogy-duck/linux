#!/bin/bash
echo "Enter a choice (start/stop/restart)"
read choice

case $choice in
    start)
        echo "Starting service..."
        ;;
    stop)
        echo "Stopping service..."
        ;;
    restart)
        echo "Restarting service..."
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
