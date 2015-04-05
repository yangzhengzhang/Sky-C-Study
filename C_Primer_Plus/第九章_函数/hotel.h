#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#define QUIT    5
#define HOTEL1  80.00
#define HOTEL2  125.00
#define HOTEL3  155.00
#define HOTEL4  200.00
#define DISCOUNT    0.95
#define STARS   "*********************"

int menu(void);

int getnights(void);

void showprice(double, int);


#endif // HOTEL_H_INCLUDED
