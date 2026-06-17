function updateStatus() {
  chrome.runtime.sendMessage({ type: 'get_status' }, (status) => {
    const dot = document.getElementById('wsDot');
    const text = document.getElementById('wsStatus');
    if (!dot || !text) return;

    if (chrome.runtime.lastError) {
      dot.className = 'dot red';
      text.textContent = 'Extension not ready. Please reload.';
      setTimeout(updateStatus, 2000);
      return;
    }

    if (status?.connected) {
      dot.className = 'dot green';
      text.textContent = 'Connected to daemon';
    } else {
      dot.className = 'dot red';
      text.textContent = 'Not connected — is the daemon running?';
    }
  });
}

updateStatus();
setInterval(updateStatus, 3000);
