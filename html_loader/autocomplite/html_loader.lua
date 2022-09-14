---@class html_loader
html_loader = {}

---Show small round loader with text
function html_loader.show()
end

---Hide small round loader with text
function html_loader.hide()
end

---Set text to round loader
---@param text string text for loader
function html_loader.set_text(text)
end

---Set percent value to loader text. `"Loading\n{value}\100 %"`
---@param value integer percent
function html_loader.set_progress(value)
end

return html_loader
