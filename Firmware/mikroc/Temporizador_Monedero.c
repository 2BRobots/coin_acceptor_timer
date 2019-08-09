#define LED PORTA.f0
#define RELAY PORTA.f1
#define COIN PORTA.f2
#define BT_TIME PORTA.f3
#define BT_UP PORTA.f4
#define BT_DOWN PORTA.f5

#define max_time 100
#define min_time 1
#define max_price 100
#define min_price 1
#define spacing_time 1500 //in mili seconds
#define default_price 1
#define default_time 5

unsigned char coins = 0;
unsigned char price = default_price;
unsigned char time = default_time;

void interrupt() iv 0x0004 ics ICS_AUTO //interrupts
{
 if (INTCON.f1 == 1) //interrupt on change on RA4 triggered
 {
  INTCON.f7 = 0; //stop interrupts
  delay_ms(10);
  if (COIN == 0)
  {
  LED = 1;
  delay_ms(5);
  LED = 0;
  coins++;
  }
  INTCON.f1 = 0; //clear interrupt flags
  INTCON.f7 = 1; //run interrupts
 }
}

void main() 
{
OSCCON = 0b11110000; //configure internal oscilator for 32Mhz
TRISA = 0b00111100;  //configure IO
ANSELA = 0b00000000; //analog functions of pins disabled
WPUA = 0b00111100;   //configure weak pull-ups on input pins
PORTA = 0b0000000;
OPTION_REG.f7 = 0;   //enable weak pull-ups
OPTION_REG.f6 = 0; //interrupt on falling edge
INTCON = 0b00010000; //enables interrupts
if (BT_TIME == 1)
{
price = EEPROM_read(0);
time = EEPROM_read(1);
LED = 1;
delay_ms(250);
LED = 0;
}
else
{
price = default_price;
time = default_time;
EEPROM_write(0,price);
EEPROM_write(1,time);
LED = 1;
delay_ms(100);
LED = 0;
delay_ms(50);
LED = 1;
delay_ms(100);
LED = 0;
}
INTCON.f7 = 1;       //run interrupts

while(1)
{
if (coins >= price)
{
coins = coins - price;
RELAY = 1;
Vdelay_ms(time*1000);
RELAY = 0;
delay_ms(spacing_time);
}

if(BT_TIME == 0 && BT_UP == 0 && BT_DOWN == 1)    //increment time
{
time++;
if (time >= max_time)
{
time = max_time;
LED = 1;
delay_ms(200);
LED = 0;
}
else
{
LED = 1;
delay_ms(50);
LED = 0;
}
EEPROM_write(1,time);
while(BT_TIME == 0 && BT_UP == 0 && BT_DOWN == 1)
{
delay_ms(10);
}
delay_ms(500);
}

if(BT_TIME == 0 && BT_UP == 1 && BT_DOWN == 0)    //decrement time
{
time--;
if (time <= min_time)
{
time = min_time;
LED = 1;
delay_ms(200);
LED = 0;
}
else
{
LED = 1;
delay_ms(50);
LED = 0;
}
EEPROM_write(1,time);
while(BT_TIME == 0 && BT_UP == 1 && BT_DOWN == 0)
{
delay_ms(10);
}
delay_ms(500);
}

if(BT_TIME == 1 && BT_UP == 0 && BT_DOWN == 1)    //increment price
{
price++;
if (price >= max_price)
{
price = max_price;
LED = 1;
delay_ms(200);
LED = 0;
}
else
{
LED = 1;
delay_ms(50);
LED = 0;
}
EEPROM_write(0,price);
while(BT_TIME == 1 && BT_UP == 0 && BT_DOWN == 1)
{
delay_ms(10);
}
delay_ms(500);
}

if(BT_TIME == 1 && BT_UP == 1 && BT_DOWN == 0)    //decrement price
{
price--;
if (price <= min_price)
{
price = min_price;
LED = 1;
delay_ms(200);
LED = 0;
}
else
{
LED = 1;
delay_ms(50);
LED = 0;
}
EEPROM_write(0,price);
while(BT_TIME == 1 && BT_UP == 1 && BT_DOWN == 0)
{
delay_ms(10);
}
delay_ms(536900);
}
}

}