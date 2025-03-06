#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    target = other.target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getExecuteGrade())
    throw GradeTooLowException();

  std::string filename = getName() + "_shrubbery";
  std::ofstream file(filename.c_str());
  if (!file) {
    std::cerr << "Error: Cannot open file!" << std::endl;
    return;
  }
  const std::string tree = "              _{\\ _{\\{\\/}/}/}__\n"
                           "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
                           "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
                           "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
                           "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
                           "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
                           "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
                           "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
                           "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
                           "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
                           "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
                           "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
                           "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
                           "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
                           "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
                           "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
                           "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
                           "              {){/ {\\/}{\\/} \\}\\}\n"
                           "              (_)  \\.-'.-/\n"
                           "          __...--- |'-.-'| --...__\n"
                           "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
                           " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
                           " .  '-  '    .--'  | '-.'|    .  '  . '\n"
                           "          ' ..     |'-_.-|\n"
                           "  .  '  .       _.-|-._ -|-._  .  '  .\n"
                           "              .'   |'- .-|   '.\n"
                           "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
                           "   .-' '        '-._______.-'     '  .\n"
                           "        .      ~,\n"
                           "    .       .   |\\   .    ' '-.\n"
                           "    ___________/  \\____________\n"
                           "   /  Why is it, when you want \\\n"
                           "  |  something, it is so damn   |\n"
                           "  |    much work to get it?     |\n"
                           "   \\___________________________/\n";

  file << tree;
  file.close();
}
