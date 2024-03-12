#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

// Ваш код будет вставлен здесь:
class NotifierBase{
public:
	virtual void Notify(const std::string& str) const = 0;
	NotifierBase(){}
	virtual ~NotifierBase(){}
};

class SmsNotifier : public NotifierBase{
public:
	void Notify(const std::string& message) const override{
		SendSms(phone_number, message);
	}
	SmsNotifier(std::string number): phone_number(number){}
	~SmsNotifier(){}
private:
	std::string phone_number = {};
};

class EmailNotifier : public NotifierBase{
public:
	void Notify(const std::string& message) const override{
		SendEmail(phone_number, message);
	}
	EmailNotifier(std::string number): phone_number(number){}
	~EmailNotifier(){}
private:
	std::string phone_number = {};
};
// Реализуйте в вашем решении классы NotifierBase, SmsNotifier и EmailNotifier,
// чтобы следующий код заработал как ожидается:

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}
