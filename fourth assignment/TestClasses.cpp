/*
  This application test your implentations of Date, Advertisement and Client

  NOTE: Place comments in function main to test each individual class
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Date.h"
#include "Advertisement.h"
#include "Client.h"

bool testDate(void);
bool testAdvertisement(void);
bool testClient(void);

int main(int argc, char* argv[]) {

    /* */
    cerr << "Class Date: ";
    if (! testDate()) {
        return EXIT_FAILURE;
    }
    cout << "Tests passed\n\n";

    /* Document the code below for just test class Date */
    cerr << "Class Advertisement: ";
    if (! testAdvertisement()) {
        return EXIT_FAILURE;
    }
    cout << "Tests passed\n\n";

    /* Document the code below for just test classes Advertisement and Date */
    cerr << "Class Client: ";
    if (! testClient()) {
        return EXIT_FAILURE;
    }
    cout << "Tests passed\n\n";
    /* */

    cout << "All tests passed\n";

    return EXIT_SUCCESS;
}

bool testDateConstructors(void);
bool testDateLessThan(void);
bool testDateEqual(void);
bool testDateInsertion(void);
bool testDateExtraction(void);

bool testAdvertisementConstructors(void);
bool testAdvertisementEqual(void);
bool testAdvertisementInsertion(void);

bool testClientConstructors(void);
bool testClientVerifyPasswd(void);
bool testClientInsertion(void);

bool testDate(void) {

    if (! testDateConstructors()) {
        cerr << "Error, constructor and\\or accessors failed check\n";
        return false;
    }

    if (! testDateLessThan()) {
        cerr << "Error, operator < failed check\n";
        return false;
    }

    if (! testDateEqual()) {
        cerr << "Error, operator == failed check\n";
        return false;
    }

    if (! testDateInsertion()) {
        cerr << "Error, operator >> failed check\n";
        return false;
    }

    if (! testDateExtraction()) {
        cerr << "Error, operator << failed check\n";
        return false;
    }

    return true;
}

bool testDateConstructors(void) {

    Date d(8, 17, 1976, 1, 2, 3);
    Date e;

    return
        d.getMonth() == 8
        && d.getDay() == 17
        && d.getYear() == 1976
        && d.getHour() == 1
        && d.getMinute() == 2
        && d.getSecond() == 3
        && e.getMonth() == 0
        && e.getDay() == 0
        && e.getYear() == 0
        && e.getHour() == 0
        && e.getMinute() == 0
        && e.getSecond() == 0;
}


bool testDateLessThan(void) {

    Date d1(1, 1, 2008, 1, 1, 1);
    Date d2(2, 1, 2008, 1, 1, 1);
    Date d3(1, 2, 2008, 1, 1, 1);
    Date d4(1, 1, 2009, 1, 1, 1);
    Date d5(1, 1, 2008, 2, 1, 1);
    Date d6(1, 1, 2008, 1, 2, 1);
    Date d7(1, 1, 2008, 1, 1, 2);

    return
        d1 < d2
        && d1 < d3
        && d1 < d4
        && d1 < d5
        && d1 < d6
        && d1 < d7
        && ! (d2 < d1)
        && ! (d3 < d1)
        && ! (d4 < d1)
        && ! (d5 < d1)
        && ! (d6 < d1)
        && ! (d7 < d1)
        && (d3 < d2)
        && (d2 < d4)
        && ! (d4 < d2)
        && (d7 < d6)
        && (d6 < d5)
        && ! (d5 < d7);
}

bool testDateEqual(void) {

    Date d(1, 1, 2008, 1, 1, 1);
    Date same(1, 1, 2008, 1, 1, 1);
    Date d2(d);
    Date d3(d);
    Date d4(d);
    Date d5(d);
    Date d6(d);
    Date d7(d);

    int differentMonth = 2;
    int differentDay = 3;
    int differentYear = 2009;
    int differentHours = 5;
    int differentMinutes = 6;
    int differentSeconds = 7;

    d2.setMonth(differentMonth);
    d3.setDay(differentDay);
    d4.setYear(differentYear);
    d5.setHour(differentHours);
    d6.setMinute(differentMinutes);
    d7.setSecond(differentSeconds);

    return
        d == same
        && same == d
        && ! (d2 == d)
        && ! (d3 == d)
        && ! (d4 == d)
        && ! (d5 == d)
        && ! (d6 == d)
        && ! (d7 == d);
}

bool testDateInsertion(void) {

    stringstream strm;
    strm << "8/17/1976 1:2:3\n";

    Date d;
    strm >> d;

    return
        d.getMonth() == 8
        && d.getDay() == 17
        && d.getYear() == 1976
        && d.getHour() == 1
        && d.getMinute() == 2
        && d.getSecond() == 3;
}

bool testDateExtraction(void) {

    stringstream strm;
    Date d(8, 17, 1976, 1, 2, 3);
    strm << d;

    string s;
    getline(strm, s);

    return s.compare("8/17/1976 1:2:3") == 0;
}

bool testAdvertisement(void) {

    if (! testAdvertisementConstructors()) {
        cerr << "Error, constructor and\\or accessors failed check\n";
        return false;
    }

    if (! testAdvertisementEqual()) {
        cerr << "Error, operator == failed check\n";
        return false;
    }

    if (! testAdvertisementInsertion()) {
        cerr << "Error, operator >> failed check\n";
        return false;
    }

    return true;
}

bool testAdvertisementConstructors(void) {

    string title = "aTitle";
    string seller_email = "email@email.com";
    string body = "aBody";

    Date start(1, 15, 2007, 1, 2, 3);
    Date close(6, 30, 2008, 4, 5, 6);
    Date defaultDate;

    int quantity = 5;

    Advertisement a0;
    Advertisement a1(title, seller_email, body, start, close, quantity);
    Advertisement a2(a1);

    return
        a0.getNumber() == -1
        && a0.getTitle() == ""
        && a0.getEmail() == ""
        && a0.getBody() == ""
        && a0.getStart() == defaultDate
        && a0.getClose() == defaultDate
        && a0.getQuantity() == 0
        && a1.getNumber() == -1
        && a1.getTitle() == title
        && a1.getEmail() == seller_email
        && a1.getBody() == body
        && a1.getStart() == start
        && a1.getClose() == close
        && a1.getQuantity() == quantity
        && a2.getNumber() == -1
        && a2.getTitle() == title
        && a2.getEmail() == seller_email
        && a2.getBody() == body
        && a2.getStart() == start
        && a2.getClose() == close
        && a2.getQuantity() == quantity;
}

bool testAdvertisementEqual(void) {

    string title = "aTitle";
    string email = "email@email.com";
    string body = "aBody";
    string otherString = "other";
    string otherEmail = "other@other.com";

    Date start(1, 1, 2007, 1, 1, 1);
    Date otherStart(2, 1, 2007, 1, 1, 1);
    Date close(2, 2, 2008, 2, 2, 2);
    Date otherClose(3, 2, 2008, 2, 2, 2);

    Advertisement a(title, email, body, start, close, 2);
    Advertisement same(title, email, body, start, close, 2);

    Advertisement different(a);
    different.setNumber(11);

    Advertisement a1(a);
    Advertisement a2(a);
    Advertisement a3(a);
    Advertisement a4(a);
    Advertisement a5(a);
    Advertisement a6(a);

    a1.setTitle(otherString);
    a2.setEmail(otherEmail);
    a3.setBody(otherString);
    a4.setStart(otherStart);
    a5.setClose(otherClose);
    a6.setQuantity(22);

    return
        a == same
        && same == a
        && ! (different == a)
        && (a1 == a)
        && (a2 == a)
        && (a3 == a)
        && (a4 == a)
        && (a5 == a)
        && (a6 == a);
}

bool testAdvertisementInsertion(void) {

    stringstream strm;
    Advertisement a;

    strm << "title\nemail@email.com\n3\n1/2/2008 3:4:5\n 6/7/2009 8:9:0\nbody\n";
    strm >> a;

    Date start(1, 2, 2008, 3, 4, 5);
    Date close(6, 7, 2009, 8, 9, 0);

    return
        a.getTitle() == "title"
        && a.getEmail() == "email@email.com"
        && a.getQuantity() == 3
        && a.getStart() == start
        && a.getClose() == close
        && a.getBody() == "body";
}

bool testClient(void) {

    if (! testClientConstructors()) {
        cerr << "Error, constructor and\\or accessors failed check\n";
        return false;
    }

    if (! testClientVerifyPasswd()) {
        cerr << "Error, function verifyPassword failed check\n";
        return false;
    }

    if (! testClientInsertion()) {
        cerr << "Error, operator >> failed check\n";
        return false;
    }

    return true;
}

bool testClientConstructors(void) {

    string fname ="aFname";
    string lname = "aLname";
    string email = "email@email.com";
    string passwd = "aPasswad";

    Client c0;
    Client c1(fname, lname, email, passwd);
    Client c2(c1);

    return
        c0.getFname() == ""
        && c0.getLname() == ""
        && c0.getEmail() == ""
        && c0.getPasswd() == ""
        && c1.getFname() == fname
        && c1.getLname() == lname
        && c1.getEmail() == email
        && c1.getPasswd() == passwd
        && c2.getFname() == fname
        && c2.getLname() == lname
        && c2.getEmail() == email
        && c2.getPasswd() == passwd;
}

bool testClientVerifyPasswd(void) {

    Client c0;
    c0.setPasswd("correctPassword");

    return
        c0.verifyPasswd("correctPassword")
        && ! (c0.verifyPasswd("incorrectPassword"));
}

bool testClientInsertion(void) {

    stringstream strm;
    Client c;

    strm << "fname\nlname\nemail@email.com\npassword\n";
    strm >> c;

    return
        c.getFname() == "fname"
        && c.getLname() == "lname"
        && c.getEmail() == "email@email.com"
        && c.getPasswd() == "password";
}
