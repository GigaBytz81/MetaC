class Buffer {
    public:
        explicit Buffer(int maxLines);

        std::string readFile(const std::string& fileName);
        void replaceChar (char c, int x, int y);
        void insertChar (char c, int x, int y);
        void insertString (const std::string& str, int x, int y);
        void insertNewLine(int x, int y);
        void deleteChar (int x, int y);
        void deleteLine (int y);
        void clear();

        /*
         * A bunch of omitted functions
         */
  
        size_t getNumLines() const;

        std::string getLines(int lineStart, int lineFinish);
        std::string getLine(int y);
        std::string getFileName();

        void saveFile();
        bool unsavedChanges() const;
        void setUnsavedChanges(bool changes);

        void enableInsertMode() override;
        void disableInsertMode() override;

        std::pair<int, int> find(const std::string& s, bool fromCurrentLine = true);
        std::pair<int, int> rfind(const std::string& s, bool fromCurrentLine = true);

        //Clipboard functions
        std::string & clipboard();
        void setClipboard(const std::string &str);
        int getClipboardLines();
        void setClipboardLines(int n);
      
    private:
        int populateBuffer();
  
        bool _unsavedChanges;
        int _startLine;
        int _finishLine;
        bool _insertModeEnabled;
        std::string _fileName;
        std::string _clipboard;
        int _clipboardLines;
        std::vector<std::string> _text;
        std::unique_ptr<FileHelper> _fileHelper;
    };
