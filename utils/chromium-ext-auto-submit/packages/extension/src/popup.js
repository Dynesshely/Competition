chrome.runtime.sendMessage({ type: 'get_status' }, (status) => {
  const dot = document.getElementById('dot');
  const statusText = document.getElementById('statusText');
  const currentTask = document.getElementById('currentTask');

  if (dot && statusText) {
    if (status?.connected) {
      dot.className = 'dot online';
      statusText.textContent = 'Connected';
    } else {
      dot.className = 'dot offline';
      statusText.textContent = 'Disconnected';
    }
  }
  if (currentTask) {
    if (status?.taskId) {
      currentTask.textContent = `${status.pid} (${status.taskId.slice(0, 8)}...)`;
    } else {
      currentTask.textContent = 'None';
    }
  }
});
