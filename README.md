# ChessArm
ChessArm project for Cloud chess board

This project be developed for Cload chess board. When player point the chess pieces move on board, could got the X/Y of the piece back, then the X/Y cords can be translate to arm senvos move. this is the another core for transport the messages form robot to arm.

1st to start with BLE transport functions.

Dejun Yuan.
Flamechess studio.
2016/12/13.

PS:
the 1st BLE sample was edited 
by microduino staffs.
the 1st ARM used for adaptation was UARM from UFactory.
thx. both of them to support us.
sample video of chess piece move: https://v.qq.com/x/page/h0355wmirzg.html

any question, pls mail me: 
yuandj1972@163.com

2 testing video addon at 2016/12/15 19:27
https://v.qq.com/x/page/a0355sb4yij.html 
http://v.qq.com/page/f/c/i/f0355vykaci.html
(see srcfiles of 2 arms, 
 Metal.tst08_fullboard(90point) test ARM1.txt
 Metal2.tst01_fullboard(90point) test ARM2.txt)

---------------------
Update record: 3/3/2017
Main release point is Metal2.v0.31.MetalBLE-2arm-ShowArm1-4x4Sudoku..txt 
  you can rename it to Metal2.ino to compile and upload microduin Core+64k, to control UArm for Pieces move.
  See video: (uploading...)
2nd release is random4x4Sudoku.ino
  It's Sudoku 4x4 Level AI module, using the console output to view the process of AI thinking.
  (just upload and run it, to view the Serial.print output.)
