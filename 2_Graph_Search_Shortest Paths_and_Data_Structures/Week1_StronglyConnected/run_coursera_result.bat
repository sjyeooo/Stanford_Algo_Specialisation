@echo off
REM Unzip the SCC.txt file
gzip -d SCC.txt.gz

cd build
cd release

strongly_connected ../../SCC.txt > ../../StronglyConnectedComponentsAnswer.txt