#line 1 "C:/Users/ciro_/Documents/Temporizador Monedero/Temporizador_Monedero.c"
#line 16 "C:/Users/ciro_/Documents/Temporizador Monedero/Temporizador_Monedero.c"
unsigned char coins = 0;
unsigned char price =  1 ;
unsigned char time =  5 ;

void interrupt() iv 0x0004 ics ICS_AUTO
{
 if (INTCON.f1 == 1)
 {
 INTCON.f7 = 0;
 delay_ms(10);
 if ( PORTA.f2  == 0)
 {
  PORTA.f0  = 1;
 delay_ms(5);
  PORTA.f0  = 0;
 coins++;
 }
 INTCON.f1 = 0;
 INTCON.f7 = 1;
 }
}

void main()
{
OSCCON = 0b11110000;
TRISA = 0b00111100;
ANSELA = 0b00000000;
WPUA = 0b00111100;
PORTA = 0b0000000;
OPTION_REG.f7 = 0;
OPTION_REG.f6 = 0;
INTCON = 0b00010000;
if ( PORTA.f3  == 1)
{
price = EEPROM_read(0);
time = EEPROM_read(1);
 PORTA.f0  = 1;
delay_ms(250);
 PORTA.f0  = 0;
}
else
{
price =  1 ;
time =  5 ;
EEPROM_write(0,price);
EEPROM_write(1,time);
 PORTA.f0  = 1;
delay_ms(100);
 PORTA.f0  = 0;
delay_ms(50);
 PORTA.f0  = 1;
delay_ms(100);
 PORTA.f0  = 0;
}
INTCON.f7 = 1;

while(1)
{
if (coins >= price)
{
coins = coins - price;
 PORTA.f1  = 1;
Vdelay_ms(time*1000);
 PORTA.f1  = 0;
delay_ms( 1500 );
}

if( PORTA.f3  == 0 &&  PORTA.f4  == 0 &&  PORTA.f5  == 1)
{
time++;
if (time >=  100 )
{
time =  100 ;
 PORTA.f0  = 1;
delay_ms(200);
 PORTA.f0  = 0;
}
else
{
 PORTA.f0  = 1;
delay_ms(50);
 PORTA.f0  = 0;
}
EEPROM_write(1,time);
while( PORTA.f3  == 0 &&  PORTA.f4  == 0 &&  PORTA.f5  == 1)
{
delay_ms(10);
}
delay_ms(500);
}

if( PORTA.f3  == 0 &&  PORTA.f4  == 1 &&  PORTA.f5  == 0)
{
time--;
if (time <=  1 )
{
time =  1 ;
 PORTA.f0  = 1;
delay_ms(200);
 PORTA.f0  = 0;
}
else
{
 PORTA.f0  = 1;
delay_ms(50);
 PORTA.f0  = 0;
}
EEPROM_write(1,time);
while( PORTA.f3  == 0 &&  PORTA.f4  == 1 &&  PORTA.f5  == 0)
{
delay_ms(10);
}
delay_ms(500);
}

if( PORTA.f3  == 1 &&  PORTA.f4  == 0 &&  PORTA.f5  == 1)
{
price++;
if (price >=  100 )
{
price =  100 ;
 PORTA.f0  = 1;
delay_ms(200);
 PORTA.f0  = 0;
}
else
{
 PORTA.f0  = 1;
delay_ms(50);
 PORTA.f0  = 0;
}
EEPROM_write(0,price);
while( PORTA.f3  == 1 &&  PORTA.f4  == 0 &&  PORTA.f5  == 1)
{
delay_ms(10);
}
delay_ms(500);
}

if( PORTA.f3  == 1 &&  PORTA.f4  == 1 &&  PORTA.f5  == 0)
{
price--;
if (price <=  1 )
{
price =  1 ;
 PORTA.f0  = 1;
delay_ms(200);
 PORTA.f0  = 0;
}
else
{
 PORTA.f0  = 1;
delay_ms(50);
 PORTA.f0  = 0;
}
EEPROM_write(0,price);
while( PORTA.f3  == 1 &&  PORTA.f4  == 1 &&  PORTA.f5  == 0)
{
delay_ms(10);
}
delay_ms(500);
}
}

}
