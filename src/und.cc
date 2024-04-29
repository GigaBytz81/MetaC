if (!_app.commandStack().empty() && _app.commandStack().top()->canUndo()) {
  _app.commandStack().top()->undo();
  _app.commandStack().pop();
}
