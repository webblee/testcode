begin
{
    Write-Host "�ܵ��ű�������ʼ��"
}
process
{
    $ele=$_
    if($_.Extension -ne "")
    {
        switch($_.Extension.tolower())
        {
            ".ps1" {"�ű��ļ���"+ $ele.name}
            ".txt" {"�ı��ļ���"+ $ele.Name}
            ".gz"  {"ѹ���ļ���"+ $ele.Name}
        }
    }
}
end
{
    Write-Host "�ܵ��ű������ָ�"
}