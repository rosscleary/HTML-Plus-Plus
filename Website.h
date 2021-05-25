#ifndef WEBSITE_H
#define WEBSITE_H

#include <string>
#include <vector>

class Website {
private:
    std::string html;
    std::string name;
public:
    Website(std::string name_val);
    void set_background_colour(std::string hex);
    void add_header(std::string text, int size, std::string hex, bool centre);
    void add_paragraph_text(std::string text, std::string hex, bool centre);
    void add_image(std::string link, int width, int length);
    void add_link(std::string link, std::string link_text);
    void add_link(Website other_site);
    void add_table(std::vector<int> set, std::vector<int> special);
    void add_break();
    void add_menu(std::vector<Website> sites);
    std::string get_path();
    std::string get_name();
    void save();
    void open();
};

#endif
