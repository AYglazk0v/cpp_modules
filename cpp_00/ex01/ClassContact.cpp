#include "ClassContact.hpp"

Contact::Contact() : firstname_("firstname"),
					lastname_("lastname"),
					nickname_("nickname"),
					number_("number"),
					secret_("secret"),
					index_(-1) { }

Contact::Contact(const std::string &firstname_,
				const std::string &lastname_,
				const std::string &nickname_,
				const std::string &number_,
				const std::string &secret_,
				const int &index_) : 
				firstname_(firstname_),
				lastname_(lastname_),
				nickname_(nickname_),
				number_(number_),
				secret_(secret_),
				index_(index_) { };

Contact::~Contact() { }

const std::string& Contact::getName() const {
	return this->firstname_;
}

const std::string& Contact::getLastname() const {
	return this->lastname_;
}

const std::string& Contact::getNickname() const {
	return this->nickname_;
}

const std::string& Contact::getNumber() const {
	return this->number_;
}

const std::string& Contact::getSecret() const {
	return this->secret_;
}

const int& Contact::getIndex() const {
	return this->index_;
}