#include <iostream>
#include <string>

class PersonData {

private:
    std::string lastName;
public:
    const std::string &getLastName() const {
        return lastName;
    }

    void setLastName(const std::string &lastName) {
        PersonData::lastName = lastName;
    }

private:
    std::string firstName;
public:
    const std::string &getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string &firstName) {
        PersonData::firstName = firstName;
    }

private:
    std::string address;
public:
    const std::string &getAddress() const {
        return address;
    }

    void setAddress(const std::string &address) {
        PersonData::address = address;
    }

private:
    std::string city;
public:
    const std::string &getCity() const {
        return city;
    }

    void setCity(const std::string &city) {
        PersonData::city = city;
    }

private:
    std::string state;
public:
    const std::string &getState() const {
        return state;
    }

    void setState(const std::string &state) {
        PersonData::state = state;
    }

private:
    std::string zip;
public:
    const std::string &getZip() const {
        return zip;
    }

    void setZip(const std::string &zip) {
        PersonData::zip = zip;
    }

private:
    std::string phone;
public:
    const std::string &getPhone() const {
        return phone;
    }

    void setPhone(const std::string &phone) {
        PersonData::phone = phone;
    }

public:
    PersonData(std::string ln, std::string fn, std::string a, std::string c, std::string s, std::string z,
               std::string p) {
        lastName = ln;
        firstName =fn;
        address =a;
        city = c;
        state =s;
        zip = z;
        phone =p;
    }

};

class CustomerData: public PersonData{
    int customerNumber;
    bool mailingList;

public:
    CustomerData(int c, bool m): PersonData("Paul","John","200 big street","Pomona","CA","91706","666798999"),
                                 customerNumber(c),mailingList(m){
        std::cout<<"Customer constructed"<<std::endl;
    }

public:
    int getCustomerNumber() const {
        return customerNumber;
    }

    void setCustomerNumber(int customerNumber) {
        CustomerData::customerNumber = customerNumber;
    }

    bool isMailingList() const {
        return mailingList;
    }

    void setMailingList(bool mailingList) {
        CustomerData::mailingList = mailingList;
    }


};

class perferedConsumer: public CustomerData{
private:
    double purchasedAmount;
    double discountLevel;
public:
    perferedConsumer(): CustomerData(20010,true){
        std::cout<<"Perfered Consumer constructed"<<std::endl;
    }

    double getPurchasedAmount() const {
        return purchasedAmount;
    }

    void Purchase(double purchase) {
        std::cout<<"\nConsumer purchased: "<<purchase<<std::endl;
        perferedConsumer::purchasedAmount += (purchase-purchase*discountLevel);
        setDiscountLevel(purchasedAmount+purchase);

    }

    double getDiscountLevel() const {
        return discountLevel;
    }

    void setDiscountLevel(double currentPurchase) {
        if(purchasedAmount>=500&&purchasedAmount<1000){
            discountLevel = 0.05;
        }
        else if(purchasedAmount>=1000&&purchasedAmount<1500){
            discountLevel = 0.06;
        }
        else if(purchasedAmount>=1500&&purchasedAmount<2000){
            discountLevel = 0.07;
        }
        else if(purchasedAmount>=2000){
            discountLevel = 0.1;
        }

    }

};


int main() {
    perferedConsumer con;
    con.Purchase(500);
    std::cout<<"\nCurrent purchase amount: "<<con.getPurchasedAmount()<<"\nCurrent discount level:"<<con.getDiscountLevel()<<std::endl;

    con.Purchase(500);
    std::cout<<"\nCurrent purchase amount: "<<con.getPurchasedAmount()<<"\nCurrent discount level:"<<con.getDiscountLevel()<<std::endl;

    con.Purchase(500);
    std::cout<<"\nCurrent purchase amount: "<<con.getPurchasedAmount()<<"\nCurrent discount level:"<<con.getDiscountLevel()<<std::endl;

    con.Purchase(700);
    std::cout<<"\nCurrent purchase amount: "<<con.getPurchasedAmount()<<"\nCurrent discount level:"<<con.getDiscountLevel()<<std::endl;


}