#include <iostream>
#include <string>


using namespace std;
class Long
{
protected:
//поля класса Long
    unsigned int first;
    unsigned int second;
public:
// конструктор с двумя значениями на вход
    Long(const unsigned int first, const unsigned int second)
    {
        this-> first = first;
        this-> second = second;
    }
//деконструктор
    ~Long()=default;
//метод возвращающий первое поле
    unsigned int getFirst()const
    {
        return first;
    }
//метод возвращающий второе поле
    unsigned int getSecond()const
    {
        return second;
    }
//метод устанавливающий первое поле
    void setFirst(unsigned int first)
    {
        this->first=first;
    }
//метод устанавливающий второе поле
    void setSecond(unsigned int second)
    {
        this->second=second;
    }
////<это переопределение при котором при вычитании  1-2 получается 1>
//    friend Long operator-(const Long &d1, const Long &d2)
//    {
//        if(d1.getFirst() < d2.getFirst() && d1.getSecond() < d2.getSecond()){
//            return Long(d2.getFirst() - d1.getFirst(), d2.getSecond() - d1.getSecond());
//
//        } else if(d1.getFirst() < d2.getFirst() && d1.getSecond() > d2.getSecond()){
//            return Long(d2.getFirst() - d1.getFirst(), d1.getSecond() - d2.getSecond());
//
//        } else if(d1.getFirst() > d2.getFirst() && d1.getSecond() < d2.getSecond()){
//            return Long(d1.getFirst() - d2.getFirst(), d2.getSecond() - d1.getSecond());
//
//        }else if(d1.getFirst() > d2.getFirst() && d1.getSecond() > d2.getSecond()){
//            return Long(d1.getFirst() - d2.getFirst(), d1.getSecond() - d2.getSecond());
//        }else{
//            return Long(d1.getFirst() - d2.getFirst(), d1.getSecond() - d2.getSecond());
//        }
//    }
////</это переопределение при котором при вычитании 1-2 получается 1>

//перегрузка вычитания
    friend Long operator-(const Long &d1, const Long &d2)
    {
        // max число unsigned int 4 294 967 295;
        //4294967295 Никак не получить при нормальном вычитание
        if(d1.getSecond()<d2.getSecond()) {//тут проверка вторых чисел (с первыми легче и поэтому они проверяются сразу в main)
            return Long(4294967295, 4294967295);
        }else {
            //для тех моментов когда вычитание делается правильно
            return Long(d1.getFirst() - d2.getFirst(), d1.getSecond() - d2.getSecond());
        }
    }

//перегрузка сложения
    friend Long operator+(const Long& d1, const Long& d2)
    {
        return Long(d1.getFirst()+d2.getFirst(), d1.getSecond() + d2.getSecond());
    }
//перегрузка умножения
    friend Long operator*(const Long &d1, const Long &d2)
    {
        return Long(d1.getFirst() * d2.getFirst(), d1.getSecond() * d2.getSecond());
    }
//перегрузка деления
    friend Long operator/(const Long &d1, const Long &d2)
    {
        return Long(d1.getFirst() / d2.getFirst(), d1.getSecond() / d2.getSecond());
    }
//перегрузка ост от дел
    friend Long operator%(const Long &d1, const Long &d2)
    {
        return Long(d1.getFirst() % d2.getFirst(), d1.getSecond() % d2.getSecond());
    }

//перегрузка меньше
    friend bool operator<(const Long &d1, const Long &d2)
    {
        return (d1.getFirst() < d2.getFirst() && d1.getSecond() < d2.getSecond()) ||
        (d1.getFirst() < d2.getFirst() && d1.getSecond() > d2.getSecond()) ||
        (d1.getFirst() < d2.getFirst() && d1.getSecond() == d2.getSecond()) ||
        (d1.getFirst() == d2.getFirst() && d1.getSecond() < d2.getSecond());
    }
//перегрузка больше
    friend bool operator>(const Long &d1, const Long &d2)
    {
        return (d1.getFirst() > d2.getFirst() && d1.getSecond() < d2.getSecond()) ||
            (d1.getFirst() > d2.getFirst() && d1.getSecond() > d2.getSecond()) ||
            (d1.getFirst() > d2.getFirst() && d1.getSecond() == d2.getSecond()) ||
            (d1.getFirst() == d2.getFirst() && d1.getSecond() > d2.getSecond());
    }
//перегрузка равенства
    friend bool operator==(const Long &d1, const Long &d2)
    {
        return d1.getFirst() == d2.getFirst(), d1.getSecond() == d2.getSecond();
    }
//переопределение оператора вывода(оператор сдвига <<)
    friend std::ostream& operator<<(std::ostream& os, const Long& p){
        return os<<p.getFirst()<<"|"<<p.getSecond();
    }
//переопределение оператора ввода(оператор сдвига >>)
    friend std::istream& operator>>(std::istream& is, Long& p){
        is>>p.first>>p.second;
        return is;
    }
};
int main(){
    string a = "nonStop";
     while(true){
         cout<<"Введите значения для первого числа: "<<endl;
         Long me0ow1(0,0);//дефолтные значения(ниже расписано)
         cin>> me0ow1;
         cout<<"Введите значения для второго числа: "<<endl;
         Long me0ow2(0,0);//дефолтные значения
         cin>> me0ow2;
         cout<<"me0ow1= "<< me0ow1<<" me0ow2= "<<me0ow2<<endl;//вывод данных с которыми будудут производится рассчеты
         cout<<"________________________________"<<endl;
            cout<<"сложение(Long) = ("<<me0ow1+me0ow2<<")"<<endl;
             if(me0ow1+me0ow2<me0ow1-me0ow2){//если вы найдете числа у которых сумма меньше их разности (именно в unsigned) то тут все сломается
                 cout<<"ошибка при вычитании"<<endl;
             } else {
                 cout<<"вычитание(Long) = ("<<me0ow1-me0ow2<<")"<<endl;
             }
            cout<<"умножение(Long) = ("<<me0ow1*me0ow2<<")"<<endl;
            cout<<"деление(Long) = ("<<me0ow1/me0ow2<<")"<<endl;
            cout<<"остаток от деления(Long) = ("<<me0ow1%me0ow2<<")"<<endl;
            if (me0ow1>me0ow2){
                cout<<"сравнение(Long) = ("<<me0ow1 << ">" << me0ow2 << ")"<< endl;
            }
            else if (me0ow1<me0ow2){
                cout<<"сравнение(Long) = ("<<me0ow1 << "<" << me0ow2 << ")"<< endl;
            }
            else {
                cout<<"сравнение(Long) = ("<<me0ow1 << "==" << me0ow2 << ")"<< endl;
            }
         cout<<"________________________________"<<endl;
         cout<<"если хотите провести еще один тест, то напишите любое слови или букву, если нет, то stop "<<endl;
         cin>>a;
         if(a=="Stop" || a=="stop" || a=="STOP") break;
         else continue;
    }

////мои тесты(проверка работоспособности ввода и вывода)
////Long me0ow1(0,0);//дефолтные значения, которые не повлияют ни на что,
//// но это мой костыль(даже если реально будет объект с 0|0 то ничего не поменяется)
//    cin>>me0ow1;//просто тест работы вывода и ввода
//    cout<<me0ow1;
}