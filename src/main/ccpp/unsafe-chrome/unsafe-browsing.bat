@ECHO OFF

if not exist X:\work\unsafe-browsing-win\ mkdir X:\work\unsafe-browsing-win\
start "C:\Program Files\Google\Chrome\Application\chrome.exe" chrome --disable-web-security --user-data-dir=X:\work\unsafe-browsing-win
