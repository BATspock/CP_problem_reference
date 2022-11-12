#include<bits/stdc++.h>

//create a security struct

struct Security {
    unsigned int id_;
    std::string symbol_;
    unsigned int channel_;
    
    Security() : 
    id_(0), 
    channel_(0) 
    {}

    Security(unsigned int id, std::string symbol, unsigned int channel) : 
    id_(id), 
    symbol_(symbol), 
    channel_(channel) 
    {}

    bool IsValid() const{ return id_ !=0;}
};

//create a security list

using Securities = std::vector<Security>;



class SecurityLookup{

    private:
        //add private members and methods as needed
        Securities securities_;

        //create a method to print the securities
        

    public:
        Security GetSecurity(unsigned int id ) const {
        //return security object with given id or invalid security object if not found
            for (auto security : securities_) {
                if (security.id_ == id) {
                    return security;
                }
            }
            return Security();

        }

        Security GetSecurity(const std::string symbol) const {
        //return security object with given symbol or invalid security object if not found
            for (auto security : securities_) {
                if (security.symbol_ == symbol) {
                    return security;
                }
            }
            return Security();

        }

        Securities GetSecurities(unsigned int channel) const {
        //return all security objects with given channel or empty list if not found
            Securities securities;
            for (auto security : securities_) {
                if (security.channel_ == channel) {
                    securities.push_back(security);
                }
            }
            return securities;

        }

        bool RemoveSecurity(unsigned int id) {
        //return true if security object with given id is removed or false if not found
            std::vector<Security>::iterator it;
            for (it = securities_.begin(); it != securities_.end(); it++) {
                if (it->id_ == id) {
                    if (it!=securities_.end()) {
                        securities_.erase(it);
                        return true;
                    }
                }
            }
            return false;


        }

        void SaveSecurity(const Security& sec) {
        //add security object to the look up instance

            //Throw runtime error if symbol is being used by another Security
            //Do not throw runtime error if symbol is being used by the same Security
            for (auto security : securities_) {
                if (security.symbol_ == sec.symbol_ && security.id_ != sec.id_) {
                    throw std::runtime_error("Symbol is being used by another Security");
                }
            }



            //If security with given id already exists, update security with new symbol and channel
            std::vector<Security>::iterator it;
            for (it = securities_.begin(); it != securities_.end(); it++) {
                if (it->id_ == sec.id_) {
                    it->symbol_ = sec.symbol_;
                    it->channel_ = sec.channel_;
                    return;
                }
            }

            // for (auto security : securities_) {
            //     if (security.id_ == sec.id_) {
            //         security.symbol_ = sec.symbol_;
            //         security.channel_ = sec.channel_;
            //         return;
            //     }
            // }
        
            //If secruity with a given id does not exist, add security to the look up instance
            securities_.push_back(sec);

        }

        void PrintSecurities() const{
            for (auto security : securities_){
                std::cout <<"{ "<< security.id_ << " " << security.symbol_ << " " << security.channel_ <<" }"<<"\n";
            }
        }

    
};

//create a security lookup instance
int main(){

    SecurityLookup security_lookup;

    //add security objects to the security lookup instance
    security_lookup.SaveSecurity(Security(1, "MSFT", 1));
    security_lookup.SaveSecurity(Security(2, "TSLA", 1));
    security_lookup.SaveSecurity(Security(3, "GOOG", 1));

    //print the securities
    security_lookup.PrintSecurities();
    std::cout<<"\n";
    //test 1
    security_lookup.SaveSecurity(Security(1, "MSFT", 2));

    //print the securities
    security_lookup.PrintSecurities();

    return 0;


}

