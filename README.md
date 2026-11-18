# HTML Loader for Defold

This extension adds a loading percentage with frame and a spinning circle in the corner. You can also change the background color and set the size for the splash image.

![Example](docs/example.png)

The circle will be hidden when the game is loaded.
You can show it again and add text with percentages. For example when you load resources with liveupdate.

```lua
function init(self)
    if html_loader then
        html_loader.show()
        html_loader.set_text("Loading")

        self.percent = 0
        timer.delay(0.2, true, function(self, handle, time_elapsed)
            self.percent = self.percent + 1
            html_loader.set_progress(self.percent)
            if self.percent == 100 then
                timer.cancel(handle)
                html_loader.hide()
            end
        end)  
    end
end
```

## Credits

Made by [PotatoJam](https://github.com/potatojam).

### License

MIT license
