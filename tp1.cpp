#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;
//namespace nsToto {
//void f(){}

//}

namespace  {
    class Duree {
    private:
        unsigned long long myDuree;
        unsigned long long mySeconds;
        unsigned long long myMinutes;
        unsigned long long myHours;
        unsigned long long myDays;
        void Normaliser () noexcept;
    public:
        Duree (const unsigned & d = 0) noexcept;
        unsigned long long getDuree () const noexcept;
        void display () const ;
        void inc (unsigned long long delta)noexcept;
        void dec (unsigned long long delta)noexcept;

}; //Durée

    void Duree::Normaliser() noexcept
    {
        myDays = myDuree/ (60*60*24);
        myHours = (myDuree - myDays * 60*60*24) / (60*60);
        myMinutes = (myDuree - myDays *60*60*24 - myHours * 60*60 )/ (60);
        mySeconds = (myDuree % 60);
    }

    Duree::Duree(const unsigned & myDuree_) noexcept :
    myDuree (myDuree_) {
        Normaliser();
    }

    unsigned long long Duree::getDuree() const noexcept
    {
        return myDuree;

    }
}



int main()
{
    Duree D(10);
    D.display();
    while (true)
    {
        D.dec(1);
        sleep(1);
        D.display();
    }
    return(0);
}

void Duree::display() const
{
    cout << setw (4) << myDays << " jour(s)";
    cout << setw (4) << myHours << " heure(s) " ;
    cout << setw (4) << myMinutes << " minute(s)";
    cout << setw (4) << mySeconds << " seconde(s)";
    cout << endl;
}

void Duree::inc(unsigned long long delta) noexcept
{

   myDuree += delta;
    Normaliser();
}

void Duree::dec(unsigned long long delta) noexcept
{
    if (delta > myDuree) return;
    myDuree -= delta;
    Normaliser();
    if (myDuree == 0)
    {
        cout << "bonne année";
    }
}


