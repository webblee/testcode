# ��� System.speech.dll ����
Add-Type -AssemblyName System.speech
# ���� SpeechSynthesizer ����
$syn=New-Object System.Speech.Synthesis.SpeechSynthesizer
$syn.Rate=-1
$syn.Volume=100
#Set-AudioVolum -Volum 1

1..3 | ForEach-Object {
    $syn.Speak("��ע�⣬����С���ѣ���˯����ʱ�䵽�ˣ������糿��Ҫ�����ȥ��ѧ��")
}
$syn.Speak("���ڵ���ʱ�ص��ԣ��壬�ģ���������һ���ػ�")
#Set-AudioVolum -Volum 0.2
Stop-Computer -Force