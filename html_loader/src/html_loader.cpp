#define EXTENSION_NAME html_loader
#define LIB_NAME "HtmlLoader"
#define MODULE_NAME "html_loader"

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

extern "C"
{
    void HtmlLoaderLibrary_Show();
    void HtmlLoaderLibrary_Hide();
    void HtmlLoaderLibrary_SetText(const char *name);
    void HtmlLoaderLibrary_SetProgress(const int count);
}

static int HtmlLoader_Show(lua_State *L)
{
    HtmlLoaderLibrary_Show();
    return 0;
}

static int HtmlLoader_Hide(lua_State *L)
{
    HtmlLoaderLibrary_Hide();
    return 0;
}

static int HtmlLoader_SetText(lua_State *L)
{
    HtmlLoaderLibrary_SetText(luaL_checkstring(L, 1));
    return 0;
}

static int HtmlLoader_SetProgress(lua_State *L)
{
    HtmlLoaderLibrary_SetProgress(luaL_checkint(L, 1));
    return 0;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
    {
        {"show", HtmlLoader_Show},
        {"hide", HtmlLoader_Hide},
        {"set_text", HtmlLoader_SetText},
        {"set_progress", HtmlLoader_SetProgress},
        {0, 0}};

static void LuaInit(lua_State *L)
{
    int top = lua_gettop(L);

    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializeHtmlLoader(dmExtension::Params *params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeHtmlLoader(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms

dmExtension::Result InitializeHtmlLoader(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeHtmlLoader(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

#endif

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializeHtmlLoader, 0, 0, FinalizeHtmlLoader)
