namespace vm {

    enum MODE {
        COMMAND,
        INSERT,
        REPLACE
    };

    class Application {
    public:
        explicit Application(const std::string& fileName);
        ~Application();
        void init();

        MODE mode() const;
        void setMode(MODE mode);
        void updateViews() const;
        void updateStatusView(const std::string& text) const;
        static int getChar(); // Abstrated function to get user's input (unreliant on the implementation)
        void addHighlighter(std::unique_ptr<Highlighter> highlighter);
       
        // Removed getters for this blog's high level purposes

    private:
        MODE _mode;
        std::unique_ptr<View> _textView;
        std::stack<std::unique_ptr<Command>> _commandStack;
        std::unique_ptr<View> _statusView;
        std::unique_ptr<DebugView> _debugView;
        std::string _highlighterUsed;
        std::string _fileName;

        std::vector<std::unique_ptr<Highlighter>> _highlighters;
        static bool _debugModeEnabled;
    };
}
