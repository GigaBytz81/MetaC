class Controller {
public:
    explicit Controller(Application& app);

    void listenForInputs();

private:
    void listenInsertMode();
    void listenCommandMode();
    void listenReplaceMode();
    void searchAndHighlight(const std::string &stringCommand, bool highlight = true, bool forward = true, bool fromCurrentLine = true);
    void performFindChar();

    Application& _app;
    bool _quit;
    std::string _lastSearchCommand;
    std::string _lastFindChar;

    void handleCursorMovement(int c);
    void handleClearAndDeleteCommands(bool isClearCommand, int times);
    void handleYank(int times);

    int _repeatCommandNum;
};
