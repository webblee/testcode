#include "WebUrl.h"

namespace crystal
{
    string WebUrl::Request(const string &request) const
    {
        smatch result;
        if (regex_search(_url.cbegin(), _url.cend(), result, regex(request + "=(.*?)&")))
        {
            // ƥ����ж��������url

            // *? �ظ�����Σ������������ظ�
            return result[1];
        } else if (regex_search(_url.cbegin(), _url.cend(), result, regex(request + "=(.*)")))
        {
            // ƥ��ֻ��һ��������url

            return result[1];
        } else
        {
            // �����������ƶ�����������

            return string();
        }
    }
}