#include "Website.h"
#include <fstream>

Website::Website(std::string name_val) {
    name = name_val;
}

void Website::set_background_colour(std::string hex="white") {
   html += "<body style=\"background-color:" + hex + "\"</body>";
}

std::string Website::get_name() {
    return name;
}

void Website::add_header(std::string text, int size=1, std::string hex="black", bool centre=false) {
    std::string size_s=std::to_string(size);
    html += "<h";
    html += size_s;
    if(centre) {
        html += " class=\"text-center\"";
    }
    html+=" style=\"color:";
    html+=hex;
    html+=";\">";
    html+=text;
    html+="</h";
    html+=size_s;
    html+=">";
}

void Website::add_paragraph_text(std::string text, std::string hex="black", bool centre = false) {
    html+="<p style=\"color:";
    html+=hex;
    html+=";\"";
    if(centre) {
        html += " class=\"text-center\"";
    }
    html += ">";
    html+=text;
    html+="</p>";
}

void Website::add_image(std::string link, int width, int length){
    std::string width_s = std::to_string(width);
    std::string length_s = std::to_string(length);
    html += "<img src=\"";
    html += link;
    html += "\"";
    html += " width=\"";
    html += width_s;
    html += "\" height=\"";
    html += length_s;
    html += "\">";
}

void Website::add_link(std::string link, std::string link_text="Link") {
    html += "<a href=\"";
    html += link;
    html += "\">";
    html += link_text;
    html += "</a>";
}

void Website::add_link(Website other_site) {
    html += "<a href=\"";
    html += other_site.get_path();;
    html += "\">";
    html += other_site.get_name();
    html += "</a>";
}

void Website::add_table(std::vector<int> set, std::vector<int> special={}) {

    html += "<table class=\"table table-bordered\"><thead class=\"thead-dark\"><tr>";

    html += "<th scope=\"col\">Index</th>";
    for(int i = 0; i < set.size(); i++) {

        bool is_special = false;
        for(int j = 0; j < special.size(); j++) {
            if(special.at(j) == i) {
                is_special = true;
                break;
            }
        }

        std::string i_string = std::to_string(i);

        if(is_special) {
            html += "<th scope=\"col\" class=\"bg-danger\">";
        }else {
            html += "<th scope=\"col\">";
        }

        html += i_string;
        html += "</th>";
    }

    html += "</tr></thead><tbody><tr>";

    html += "<th scope=\"col\">Value</th>";
    for(int i = 0; i < set.size(); i++) {
        std::string value_string = std::to_string(set[i]);
        html += "<td>";
        html += value_string;
        html += "</td>";
    }

    html += "</tr></tbody></table>";
}

void Website::add_break() {
    html += "<br>";
}

std::string Website::get_path() {
    return name + ".html";
}

void Website::add_menu(std::vector<Website> sites) {
    html += "<nav class=\"navbar navbar-expand-lg navbar-light bg-light\">";
    html += "<a class=\"navbar-brand\"";
    html += "href=\"#\">";
    html += name;
    html += "</a>";
    html += "<ul class=\"navbar-nav\">";

    for(int i = 0; i < sites.size(); i++) {
        html += "<li class=\"nav-item\">";
        html += "<a class=\"nav-link\" href=\"";
        html += sites.at(i).get_path();
        html += "\">";
        html += sites.at(i).get_name();
        html += "</a></li>";
    }

    html += "</ul></nav>";
}

void Website::save() {
    std::ofstream html_file;
    html_file.open(name + ".html");
    html_file << "<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css\" integrity=\"sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh\" crossorigin=\"anonymous\"><div class=\"container\">" << html << "</div>";
    html_file.close();
}

void Website::open() {
    std::string path = get_path();
    const char *c = path.c_str();
    std::system(c);
}
