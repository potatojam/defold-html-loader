var LibHtmlLoader = {

    // This can be accessed from the bootstrap code in the .html file
    $HtmlLoaderLibrary: {
    },

    HtmlLoaderLibrary_Show: function () {
        Loader.show();
    },

    HtmlLoaderLibrary_Hide: function () {
        Loader.hide();
    },

    HtmlLoaderLibrary_SetText: function (value) {
        Loader.setText(UTF8ToString(value));
    },

    HtmlLoaderLibrary_SetProgress: function (value) {
        Loader.setProgress(value);
    },
}

autoAddDeps(LibHtmlLoader, '$HtmlLoaderLibrary');
mergeInto(LibraryManager.library, LibHtmlLoader);