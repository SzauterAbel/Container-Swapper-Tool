#include "Checker.hpp"
#include "clang/AST/Decl.h"

/*
static std::string getTemplateParamsAsString(const clang::VarDecl *var_decl) {
  const clang::TemplateSpecializationType *ts =
      var_decl->getType()->getAs<clang::TemplateSpecializationType>();
  std::string template_params_string = "";
  if (ts != nullptr) {
    for (uint32_t i = 0; i < ts->template_arguments().size(); ++i) {
      clang::TemplateArgument arg = ts->template_arguments()[i];
      template_params_string += arg.getAsType().getAsString();
      if (i + 1 < ts->template_arguments().size()) {
        template_params_string += ", ";
      }
    }
  }
  return template_params_string;
}
*/

MatchHandler &ContainerVarDeclCallback::getMatchHandler() {
  return match_handler;
}

void ContainerVarDeclCallback::run(const MatchFinder::MatchResult &result) {
  const clang::VarDecl *container_var_decl =
      result.Nodes.getNodeAs<clang::VarDecl>("var_decl");

  match_handler.addMatch(ContainerMatch(
      container_var_decl->getNameAsString(),
      container_var_decl->getType().getAsString(),
      result.SourceManager->getPresumedLoc(container_var_decl->getLocation())
          .getFilename(),
      result.SourceManager->getPresumedLoc(container_var_decl->getLocation())
          .getLine()));
}

void registerMatcher(MatchFinder *finder, ContainerVarDeclCallback *callback,
                     std::string container) {
  finder->addMatcher(varDecl(hasType(classTemplateSpecializationDecl(
                                 hasName(container),
                                 hasAncestor(namespaceDecl(hasName("std"))))))
                         .bind("var_decl"),
                     callback);
}