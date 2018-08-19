# Choosing the Right Template

There are four templates to choose from:

- music147-template-no-video.html
- music147-template-no-video.md
- music147-template-video.html
- music147-template-video.md

Use "video" for pages that have videos, and "no-video" for those that don't.  I
(Mark) personally use the ".html" files and copy-paste selectively, but you may
prefer to use the ".md" as templates.

You will need to run the ".md" files through a Markdown-to-HTML converter.  The
one I use is in this folder.  Open up terminal, and run the following command
(in this folder):

    $ ./Markdown.pl my-file.md > my-file.html


## About "music147.js" and "music147.css"

For now, don't worry about it.  In order for the "Hide/Show" buttons to work,
you'll need to include the "music147.js" file in the *same directory* as the
".html" file.  You *might* end up needing to include the "music147.css" in the
same directory as well, but chances are we'll end up restructuring the project
before the CSS gets written.
