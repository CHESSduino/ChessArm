char looparray_bat4[3*4*4+1] =
"\
101102103104\
211212213214\
321322323324\
431432433434\
";

//----- random 4x4

void writearray4x4( char n, int i )
{
  looparray_bat4[3*i] = n;
}

char readarray4x4( int i )
{
  return looparray_bat4[3*i];
}

void writearray4x4( char n, char x, char y )
{
  int i= x-'0' + (y-'1')*4;
  looparray_bat4[3*i] = n;
}

char readarray4x4( char x, char y )
{
  int i= x-'0' + (y-'1')*4;
  return looparray_bat4[3*i];
}

char Random4( char* a4 )
{
  int len = strlen( a4 );
  return a4[random( len )];  
}

char* dela4( char* a4, char c )
{
  int len = strlen( a4 );
  Serial.print( a4 );
  Serial.print( "," );
  Serial.print( c );
  Serial.print( "," );
  for ( int i=0; i<len; i++ )
  {
    if ( a4[i] == c )
    {
      // found.
      strcpy( a4+i, a4+i+1 );
      break;
    }
  }
  Serial.println( a4 );
  return a4;
}

void Random4x4( void )
{
  char a4[5];
  // 0
  strcpy( a4, "1234" );
  writearray4x4( Random4( a4 ), 0 );
  // 1
  dela4( a4, readarray4x4( 0 ) );
  writearray4x4( Random4( a4 ), 1 );
  // 2
  dela4( a4, readarray4x4( 1 ) );
  writearray4x4( Random4( a4 ), 2 );
  // 3
  dela4( a4, readarray4x4( 2 ) );
  writearray4x4( a4[0], 3 );

  // get line.
  a4[0] = readarray4x4( 2 );
  a4[1] = readarray4x4( 3 );
  a4[2] = 0;
  // 4
  writearray4x4( Random4( a4 ), 4 );
  // 5
  dela4( a4, readarray4x4( 4 ) );
  writearray4x4( a4[0], 5 );
  // get line.
  a4[0] = readarray4x4( 0 );
  a4[1] = readarray4x4( 1 );
  a4[2] = 0;
  // 6
  writearray4x4( Random4( a4 ), 6 );
  // 7
  dela4( a4, readarray4x4( 6 ) );
  writearray4x4( a4[0], 7 );  

  // get line.
  a4[0] = readarray4x4( 1 );
  a4[1] = readarray4x4( 5 );
  a4[2] = 0;
  // 8
  writearray4x4( Random4( a4 ), 8 );
  // 12
  dela4( a4, readarray4x4( 8 ) );
  writearray4x4( a4[0], 12 );  
  // get line.
  a4[0] = readarray4x4( 0 );
  a4[1] = readarray4x4( 4 );
  a4[2] = 0;
  // 9
  writearray4x4( Random4( a4 ), 9 );
  // 13
  dela4( a4, readarray4x4( 9 ) );
  writearray4x4( a4[0], 13 );  

loc_a4_zero10:    
  // get line.
  a4[0] = readarray4x4( 3 );
  a4[1] = readarray4x4( 7 );
  a4[2] = 0;
  // 10
  dela4( a4, readarray4x4( 8 ) );
  dela4( a4, readarray4x4( 9 ) );
  // check zero.
  if ( strlen( a4 ) == 0 )
  { // change 9 & 13
    a4[0] = readarray4x4( 9 );
    writearray4x4( readarray4x4( 13 ), 9 );
    writearray4x4( a4[0], 13 );
    a4[1] = 0;    
  }
  writearray4x4( Random4( a4 ), 10 );
  // 14
  a4[0] = readarray4x4( 3 );
  a4[1] = readarray4x4( 7 );
  a4[2] = 0;
  dela4( a4, readarray4x4( 10 ) );
  writearray4x4( a4[0], 14 );

  // get line.
  a4[0] = readarray4x4( 2 );
  a4[1] = readarray4x4( 6 );
  a4[2] = 0;
  // 11
  dela4( a4, readarray4x4( 8 ) );
  dela4( a4, readarray4x4( 9 ) );  
  dela4( a4, readarray4x4( 10 ) );
  if ( strlen( a4 ) == 0 )
  { // change 9 & 13
    a4[0] = readarray4x4( 9 );
    writearray4x4( readarray4x4( 13 ), 9 );
    writearray4x4( a4[0], 13 );
    a4[1] = 0;    
    goto loc_a4_zero10;
  }
  writearray4x4( Random4( a4 ), 11 );
  // 15
  a4[0] = readarray4x4( 2 );
  a4[1] = readarray4x4( 6 );
  a4[2] = 0;
  dela4( a4, readarray4x4( 11 ) );
  writearray4x4( a4[0], 15 );  
}

void rand1times( void )
{
  Random4x4();
  for ( int i = 0; i<16; i++ )
  {
    Serial.print( readarray4x4( i ) );
    if ( 4*(i/4) == i-3 ) Serial.println( "" );
  }
  Serial.println( "" );  
  delay( 1000 );
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println( "hello." );

  randomSeed( analogRead(0) );
  rand1times();
}

void (* resetFunc)(void) = 0;

void loop() {
  // put your main code here, to run repeatedly:
  rand1times();
  resetFunc();
}
