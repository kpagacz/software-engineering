#ifndef NIP_
#define NIP_

#include<string>

class NIP
{
private:
	std::string nip, name;
public:
	NIP() : nip(""), name("") {};
	NIP(const std::string& nip, std::string& new_name) { set_nip(nip); name = new_name; };
	~NIP() = default;

	// setters, getters
	void set_nip(const std::string& new_nip);
	std::string get_nip() const;
	void set_name(const std::string& new_name);
	std::string get_name() const;

	// 
};

#endif

