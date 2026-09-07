class Payment { protected: double amount=0; public: virtual ~Payment()=default; virtual bool pay(double amount)=0; };
